// file: binary_ops_typed_tests.cpp

#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

// ---- Your actual node system ----
#include <node/abstract_node.hpp>
#include <abstract_discrete_time_online_interpreter.hpp>

#include <node/arithmetic/addition.hpp>
#include <node/arithmetic/subtraction.hpp>
#include <node/arithmetic/multiplication.hpp>
#include <node/arithmetic/division.hpp>
#include <node/arithmetic/pow.hpp>
#include <node/arithmetic/log.hpp>

#include <node/ltl/disjunction.hpp>
#include <node/ltl/conjunction.hpp>
#include <node/ltl/xor.hpp>
#include <node/ltl/iff.hpp>
#include <node/ltl/implies.hpp>

#include <node/ltl/variable.hpp>

#include <time_interpreter.hpp>

using namespace stl_library;

// ===========================================================
// Your typedefs come from the headers:
//   typedef std::shared_ptr<AbstractNode> PNode;
//   typedef std::map<std::string,double>  DataSet;
// ===========================================================

using InputContext = DataSet;

// ===========================================================
// OPERATOR TRAITS
//   - symbol_token: substring expected in getName()
//   - apply: robustness semantics for evaluation comparison
//   - commutative: property check
// ===========================================================

template <typename Op> struct OpTraits;

// ---- Arithmetic ----
template <> struct OpTraits<AdditionNode> {
    static constexpr const char* name = "AdditionNode";
    static constexpr const char* symbol_token = "+";
    static double apply(double a, double b) { return a + b; }
    static constexpr bool commutative = true;
};

template <> struct OpTraits<SubtractionNode> {
    static constexpr const char* name = "SubtractionNode";
    static constexpr const char* symbol_token = "-";
    static double apply(double a, double b) { return a - b; }
    static constexpr bool commutative = false;
};

template <> struct OpTraits<MultiplicationNode> {
    static constexpr const char* name = "MultiplicationNode";
    static constexpr const char* symbol_token = "*";
    static double apply(double a, double b) { return a * b; }
    static constexpr bool commutative = true;
};

template <> struct OpTraits<DivisionNode> {
    static constexpr const char* name = "DivisionNode";
    static constexpr const char* symbol_token = "/";
    static double apply(double a, double b) { return a / b; }
    static constexpr bool commutative = false;
};

template <> struct OpTraits<PowNode> {
    static constexpr const char* name = "PowNode";
    static constexpr const char* symbol_token = "pow";   // getName(): "pow(phi1, phi2)"
    static double apply(double a, double b) { return std::pow(a, b); }
    static constexpr bool commutative = false;
};

template <> struct OpTraits<LogNode> {
    static constexpr const char* name = "LogNode";
    static constexpr const char* symbol_token = "log";   // getName(): "log(phi1, phi2)"
    static double apply(double a, double b) { return std::log(a) / log(b); }
    static constexpr bool commutative = false;
};

// ---- Logical (LTL) with robustness semantics ----
template <> struct OpTraits<ConjunctionNode> {
    static constexpr const char* name = "ConjunctionNode";
    static constexpr const char* symbol_token = "and";   // getName includes "and"
    static double apply(double a, double b) { return std::min(a, b); }  // AND = min
    static constexpr bool commutative = true;
};

template <> struct OpTraits<DisjunctionNode> {
    static constexpr const char* name = "DisjunctionNode";
    static constexpr const char* symbol_token = "or";    // getName includes "or"
    static double apply(double a, double b) { return std::max(a, b); }  // OR = max
    static constexpr bool commutative = true;
};

template <> struct OpTraits<XorNode> {
    static constexpr const char* name = "XorNode";
    static constexpr const char* symbol_token = "xor";   // getName includes "xor"
    static double apply(double a, double b) { return std::abs(a - b); } // XOR = |a-b|
    static constexpr bool commutative = true;
};

template <> struct OpTraits<IffNode> {
    static constexpr const char* name = "IffNode";
    static constexpr const char* symbol_token = "<->";   // getName: "(L)<->(R)"
    static double apply(double a, double b) { return -std::abs(a - b); } // IFF = -|a-b|
    static constexpr bool commutative = true;
};

template <> struct OpTraits<ImpliesNode> {
    static constexpr const char* name = "ImpliesNode";
    static constexpr const char* symbol_token = "->";    // getName: "(L)->(R)"
    static double apply(double a, double b) { return std::max(-a, b); } // IMPLIES = max(-a,b)
    static constexpr bool commutative = false;
};

// ===========================================================
// Pretty type-name printer for GoogleTest
// ===========================================================

struct OpTypeNames {
    template <typename T>
    static std::string GetName(int) {
        return OpTraits<T>::name;
    }
};

// ===========================================================
// Typed Fixture
// ===========================================================

template <typename T>
class BinaryOpTests : public ::testing::Test {
public:
    using Op = T;
    using Traits = OpTraits<T>;
};

// ---- Operator types under test ----
using BinaryOperators = ::testing::Types<
    AdditionNode,
    SubtractionNode,
    MultiplicationNode,
    DivisionNode,
    PowNode,
    LogNode,
    ConjunctionNode,
    DisjunctionNode,
    XorNode,
    IffNode,
    ImpliesNode
>;

TYPED_TEST_SUITE(BinaryOpTests, BinaryOperators, OpTypeNames);

// ===========================================================
// Helper: construct Op(phi1, phi2)
// ===========================================================

template <typename Op>
static std::shared_ptr<Op> make_op() {
    PNode phi1 = std::make_shared<VariableNode>("phi1");
    PNode phi2 = std::make_shared<VariableNode>("phi2");
    return std::make_shared<Op>(phi1, phi2);
}

// ===========================================================
// TESTS
// ===========================================================

// 1) Construction
TYPED_TEST(BinaryOpTests, ConstructsNotNull) {
    auto root = make_op<typename TestFixture::Op>();
    ASSERT_NE(root, nullptr);
}

// 2) Children via getChildren().at(0/1)
TYPED_TEST(BinaryOpTests, ChildrenLinkedCorrectly) {
    PNode left = std::make_shared<VariableNode>("phi1");
    PNode right = std::make_shared<VariableNode>("phi2");

    auto root = std::make_shared<typename TestFixture::Op>(left, right);

    ASSERT_EQ(root->getChildren().size(), 2u);
    EXPECT_EQ(root->getChildren().at(0), left);
    EXPECT_EQ(root->getChildren().at(1), right);
}

// 3) getName() contains variables and operator token
TYPED_TEST(BinaryOpTests, NameContainsVariablesAndOperatorToken) {
    auto root = make_op<typename TestFixture::Op>();
    const std::string name = root->getName();

    EXPECT_NE(name.find("phi1"), std::string::npos);
    EXPECT_NE(name.find("phi2"), std::string::npos);
    EXPECT_NE(name.find(TestFixture::Traits::symbol_token), std::string::npos);

    // Optional (stricter): ensure function-style like "pow(" or text token present
    // EXPECT_NE(name.find(std::string(TestFixture::Traits::symbol_token) + "("), std::string::npos);
}

// 4) Interpreter-based evaluation vs robustness semantics
TYPED_TEST(BinaryOpTests, EvaluationViaInterpreterMatchesRobustSemantics) {
    using Traits = typename TestFixture::Traits;

    auto root = make_op<typename TestFixture::Op>();

    struct Case { double a, b; };
    const std::vector<Case> cases = {
        {  1.0,  2.0 },
        {  5.0,  5.0 },
        {  0.0,  7.0 },
        { -3.0,  6.0 },
        { 10.0, -4.0 }
    };

    for (const auto& tc : cases) {
        InputContext input;
        input["phi1"] = tc.a;
        input["phi2"] = tc.b;

        DiscreteTimeOnlineInterpreter interpreter(root);
        interpreter.set_ast(root);

        const double got = interpreter.update(0, input);
        const double exp = Traits::apply(tc.a, tc.b);


        if (std::isinf(exp) && std::isinf(got)) {
            EXPECT_EQ(std::signbit(got), std::signbit(exp))
                << "Operator=" << Traits::name
                << " a=" << tc.a << " b=" << tc.b;
        }
        else if (std::isnan(exp)) {
            EXPECT_TRUE(std::isinf(got) && got < 0)
                << "Operator=" << Traits::name
                << " a=" << tc.a << " b=" << tc.b;
        }
        else {
            EXPECT_NEAR(got, exp, 1e-9)
                << "Operator=" << Traits::name
                << " a=" << tc.a << " b=" << tc.b;
        }

    }
}

// 5) Commutativity property where applicable
TYPED_TEST(BinaryOpTests, CommutativityCheck) {
    using Op = typename TestFixture::Op;
    using Traits = typename TestFixture::Traits;

    if constexpr (Traits::commutative) {
        PNode a = std::make_shared<VariableNode>("phi1");
        PNode b = std::make_shared<VariableNode>("phi2");

        auto op_ab = std::make_shared<Op>(a, b);
        auto op_ba = std::make_shared<Op>(b, a);

        InputContext input;
        input["phi1"] = 3.0;
        input["phi2"] = 7.0;

        DiscreteTimeOnlineInterpreter i1(op_ab);
        DiscreteTimeOnlineInterpreter i2(op_ba);
        i1.set_ast(op_ab);
        i2.set_ast(op_ba);

        EXPECT_NEAR(i1.update(0, input), i2.update(0, input), 1e-9)
            << "Commutativity failed for " << Traits::name;
    }
    else {
        SUCCEED();
    }
}