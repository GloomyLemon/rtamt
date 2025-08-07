// file: unary_ops_typed_tests.cpp

#include <gtest/gtest.h>
#include <cmath>
#include <map>
#include <memory>
#include <string>
#include <vector>

// ---- Your node system ----
#include <node/abstract_node.hpp>
#include <abstract_discrete_time_online_interpreter.hpp>

// Arithmetic unary ops
#include <node/arithmetic/negate.hpp>
#include <node/arithmetic/sqrt.hpp>
#include <node/arithmetic/exp.hpp>
#include <node/arithmetic/abs.hpp>

// Logical unary NOT
#include <node/ltl/neg.hpp>

// Variable
#include <node/ltl/variable.hpp>

#include <time_interpreter.hpp>

using namespace stl_library;

// Your typedefs come from the headers:
//   typedef std::shared_ptr<AbstractNode> PNode;
//   typedef std::map<std::string,double>  DataSet;
using InputContext = DataSet;

// ===========================================================
// UNARY OP TRAITS
//   - token: substring expected in getName()
//   - apply: numeric/robust semantics to compare against interpreter
//   - valid: domain validity (sqrt invalid for x<0)
//   - double_negation: property test for NOT/NEGATE
//   - idempotent_abs: property test for abs(abs(x)) == abs(x)
// ===========================================================

template <typename Op>
struct UnaryOpTraits {
    static constexpr const char* name = "UnknownUnary";
    static constexpr const char* token = "";
    static bool   valid(double a) { return true; }
    static double apply(double a) { return a; }
    static constexpr bool double_negation = false;
    static constexpr bool idempotent_abs = false;
};

// ---- Logical NOT: NotNode => robust NOT = -a ----
template<>
struct UnaryOpTraits<NotNode> {
    static constexpr const char* name = "NotNode";
    static constexpr const char* token = "!";  // change to "!" if getName uses symbol
    static bool valid(double) { return true; }
    static double apply(double a) { return -a; }
    static constexpr bool double_negation = true;   // not(not(a)) = a
    static constexpr bool idempotent_abs = false;
};

// ---- Arithmetic NEGATION: NegateNode => -a ----
template<>
struct UnaryOpTraits<NegateNode> {
    static constexpr const char* name = "NegateNode";
    static constexpr const char* token = "-";    // change to "negate" if function-style
    static bool valid(double) { return true; }
    static double apply(double a) { return -a; }
    static constexpr bool double_negation = true;   // -(-a) = a
    static constexpr bool idempotent_abs = false;
};

// ---- SqrtNode: sqrt(a) ----
template<>
struct UnaryOpTraits<SqrtNode> {
    static constexpr const char* name = "SqrtNode";
    static constexpr const char* token = "sqrt";
    static bool valid(double a) { return a >= 0.0; }
    static double apply(double a) { return std::sqrt(a); }
    static constexpr bool double_negation = false;
    static constexpr bool idempotent_abs = false;
};

// ---- ExpNode: exp(a) = e^a ----
template<>
struct UnaryOpTraits<ExpNode> {
    static constexpr const char* name = "ExpNode";
    static constexpr const char* token = "exp";
    static bool valid(double) { return true; }
    static double apply(double a) { return std::exp(a); }
    static constexpr bool double_negation = false;
    static constexpr bool idempotent_abs = false;
};

// ---- AbsNode: abs(a) ----
template<>
struct UnaryOpTraits<AbsNode> {
    static constexpr const char* name = "AbsNode";
    static constexpr const char* token = "abs";
    static bool valid(double) { return true; }
    static double apply(double a) { return std::abs(a); }
    static constexpr bool double_negation = false;
    static constexpr bool idempotent_abs = true;   // abs(abs(a)) = abs(a)
};

// ===========================================================
// Typed Fixture
// ===========================================================

template<typename T>
class UnaryOpTests : public ::testing::Test {
public:
    using Op = T;
    using Traits = UnaryOpTraits<T>;
};

using UnaryOperators = ::testing::Types<
    NotNode,     // logical robust NOT
    NegateNode,  // arithmetic negation
    SqrtNode,
    ExpNode,
    AbsNode
>;

struct UnaryNamePrinter {
    template<typename T> static std::string GetName(int) {
        return UnaryOpTraits<T>::name;
    }
};

TYPED_TEST_SUITE(UnaryOpTests, UnaryOperators, UnaryNamePrinter);

// ===========================================================
// Helpers
// ===========================================================

template<typename Op>
std::shared_ptr<Op> make_unary() {
    PNode phi = std::make_shared<VariableNode>("phi1");
    return std::make_shared<Op>(phi);
}

// ===========================================================
// TESTS
// ===========================================================

TYPED_TEST(UnaryOpTests, ConstructsNotNull) {
    ASSERT_NE(make_unary<typename TestFixture::Op>(), nullptr);
}

TYPED_TEST(UnaryOpTests, ChildCorrect) {
    PNode c = std::make_shared<VariableNode>("phi1");
    auto root = std::make_shared<typename TestFixture::Op>(c);
    ASSERT_EQ(root->getChildren().size(), 1u);
    EXPECT_EQ(root->getChildren().at(0), c);
}

TYPED_TEST(UnaryOpTests, NameContainsTokenAndVar) {
    auto root = make_unary<typename TestFixture::Op>();
    std::string name = root->getName();
    EXPECT_NE(name.find("phi1"), std::string::npos);
    EXPECT_NE(name.find(TestFixture::Traits::token), std::string::npos);
    // Optional stricter variant if your getName is function-style:
    // EXPECT_NE(name.find(std::string(TestFixture::Traits::token) + "("), std::string::npos);
}

TYPED_TEST(UnaryOpTests, EvaluateMatchesSemantic) {
    using Traits = typename TestFixture::Traits;
    auto root = make_unary<typename TestFixture::Op>();

    std::vector<double> vals = { -5, -1, 0, 1, 2, 10 };

    for (double a : vals) {
        InputContext ctx;
        ctx["phi1"] = a;

        DiscreteTimeOnlineInterpreter I(root);
        I.set_ast(root);
        double got = I.update(0, ctx);

        if (Traits::valid(a)) {
            double exp = Traits::apply(a);
            if (std::isnan(exp))
                EXPECT_TRUE(std::isnan(got));
            else
                EXPECT_NEAR(got, exp, 1e-9) << "a=" << a;
        }
        else {
            EXPECT_TRUE(std::isnan(got)) << "Expected NaN for invalid domain, a=" << a;
        }
    }
}

// Double negation: not(not(a)) = a, -(-a) = a
TYPED_TEST(UnaryOpTests, DoubleNegationIfApplicable) {
    using Op = typename TestFixture::Op;
    using Traits = typename TestFixture::Traits;

    if constexpr (Traits::double_negation) {
        PNode phi = std::make_shared<VariableNode>("phi1");
        auto n1 = std::make_shared<Op>(phi);
        auto n2 = std::make_shared<Op>(n1); // Op(Op(phi1))

        DiscreteTimeOnlineInterpreter I(n2);
        I.set_ast(n2);

        DiscreteTimeOnlineInterpreter J(phi);
        J.set_ast(phi);

        for (double a : { -5, -1, 0, 1, 7 }) {
            InputContext ctx; ctx["phi1"] = a;
            EXPECT_NEAR(I.update(0, ctx), J.update(0, ctx), 1e-9) << "a=" << a;
        }
    }
    else {
        SUCCEED();
    }
}

// Abs idempotence: abs(abs(x)) == abs(x)
TYPED_TEST(UnaryOpTests, AbsIdempotentIfApplicable) {
    using Op = typename TestFixture::Op;
    using Traits = typename TestFixture::Traits;

    if constexpr (Traits::idempotent_abs) {
        PNode phi = std::make_shared<VariableNode>("phi1");
        auto abs1 = std::make_shared<Op>(phi);
        auto abs2 = std::make_shared<Op>(abs1);

        DiscreteTimeOnlineInterpreter I(abs2);
        I.set_ast(abs2);

        DiscreteTimeOnlineInterpreter J(abs1);
        J.set_ast(abs1);

        for (double a : { -7, -1, 0, 2, 10 }) {
            InputContext ctx; ctx["phi1"] = a;
            EXPECT_NEAR(I.update(0, ctx), J.update(0, ctx), 1e-9) << "a=" << a;
        }
    }
    else {
        SUCCEED();
    }
}