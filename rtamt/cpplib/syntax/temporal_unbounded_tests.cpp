// file: temporal_ops_typed_tests.cpp

#include <gtest/gtest.h>
#include <cmath>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

// AST base + interpreter
#include <node/abstract_node.hpp>
#include <abstract_discrete_time_online_interpreter.hpp>

// Unary temporal nodes (symbolic: G F H O P)
#include <node/ltl/always.hpp>        // G
#include <node/ltl/eventually.hpp>    // F
#include <node/ltl/historically.hpp>  // H
#include <node/ltl/once.hpp>          // O
#include <node/ltl/previous.hpp>      // P

// Binary temporal operator: S
#include <node/ltl/since.hpp>

// Variable node
#include <node/ltl/variable.hpp>

// Interpreter
#include <time_interpreter.hpp>

using namespace stl_library;

using InputContext = DataSet;
using PNode = std::shared_ptr<AbstractNode>;

//
// ===============================================================
// UNARY TEMPORAL TRAITS — OPERATOR SYMBOL TOKENS
// ===============================================================
//

template <typename Op>
struct TemporalUnaryTraits {
    static constexpr const char* name = "UnknownTemporalUnary";
    static constexpr const char* token = "";   // substring expected in getName()
    static double apply(const std::vector<double>& h, int t) { return 0.0; }
};

// G φ = min(0..t)
template<>
struct TemporalUnaryTraits<AlwaysNode> {
    static constexpr const char* name = "AlwaysNode";
    static constexpr const char* token = "G";
    static double apply(const std::vector<double>& h, int t) {
        double r = h[0];
        for (int i = 1; i <= t; ++i)
            r = std::min(r, h[i]);
        return r;
    }
};

// F φ = max(0..t)
template<>
struct TemporalUnaryTraits<EventuallyNode> {
    static constexpr const char* name = "EventuallyNode";
    static constexpr const char* token = "F";
    static double apply(const std::vector<double>& h, int t) {
        double r = h[0];
        for (int i = 1; i <= t; ++i)
            r = std::max(r, h[i]);
        return r;
    }
};

// H φ = min(0..t)
template<>
struct TemporalUnaryTraits<HistoricallyNode> {
    static constexpr const char* name = "HistoricallyNode";
    static constexpr const char* token = "H";
    static double apply(const std::vector<double>& h, int t) {
        double r = h[0];
        for (int i = 1; i <= t; ++i)
            r = std::min(r, h[i]);
        return r;
    }
};

// O φ = max(0..t)
template<>
struct TemporalUnaryTraits<OnceNode> {
    static constexpr const char* name = "OnceNode";
    static constexpr const char* token = "O";
    static double apply(const std::vector<double>& h, int t) {
        double r = h[0];
        for (int i = 1; i <= t; ++i)
            r = std::max(r, h[i]);
        return r;
    }
};

// P φ(t) = φ(t−1), P φ(0) = +∞
// (matches StlPreviousNode::prev_in = +∞)
template<>
struct TemporalUnaryTraits<PreviousNode> {
    static constexpr const char* name = "PreviousNode";
    static constexpr const char* token = "P";
    static double apply(const std::vector<double>& h, int t) {
        return (t == 0)
            ? std::numeric_limits<double>::infinity()
            : h[t - 1];
    }
};

//
// ===============================================================
// UNARY TEMPORAL TYPED FIXTURE
// ===============================================================
//

template <typename T>
class TemporalUnaryTests : public ::testing::Test {
public:
    using Op = T;
    using Traits = TemporalUnaryTraits<T>;
};

using TemporalUnaryOps = ::testing::Types<
    AlwaysNode,
    EventuallyNode,
    HistoricallyNode,
    OnceNode,
    PreviousNode
>;

struct TemporalUnaryNamePrinter {
    template<typename T>
    static std::string GetName(int) { return TemporalUnaryTraits<T>::name; }
};

TYPED_TEST_SUITE(TemporalUnaryTests, TemporalUnaryOps, TemporalUnaryNamePrinter);

template<typename Op>
std::shared_ptr<Op> make_temporal_unary() {
    PNode phi = std::make_shared<VariableNode>("phi1");
    return std::make_shared<Op>(phi);
}

//
// ===============================================================
// UNARY TEMPORAL TESTS
// ===============================================================
//

TYPED_TEST(TemporalUnaryTests, ConstructsNotNull) {
    ASSERT_NE(make_temporal_unary<typename TestFixture::Op>(), nullptr);
}

TYPED_TEST(TemporalUnaryTests, ChildCorrect) {
    PNode child = std::make_shared<VariableNode>("phi1");
    auto node = std::make_shared<typename TestFixture::Op>(child);

    ASSERT_EQ(node->getChildren().size(), 1u);
    EXPECT_EQ(node->getChildren().at(0), child);
}

TYPED_TEST(TemporalUnaryTests, NameContainsSymbolAndVar) {
    auto root = make_temporal_unary<typename TestFixture::Op>();
    std::string name = root->getName();

    EXPECT_NE(name.find("phi1"), std::string::npos);
    EXPECT_NE(name.find(TestFixture::Traits::token), std::string::npos);
}

TYPED_TEST(TemporalUnaryTests, EvaluationMatchesRobustSemantics) {
    using Traits = typename TestFixture::Traits;

    std::vector<double> samples = { 1.0, -2.0, 3.0, -1.0 };

    auto root = make_temporal_unary<typename TestFixture::Op>();
    DiscreteTimeOnlineInterpreter I(root);
    I.set_ast(root);

    for (int t = 0; t < samples.size(); ++t) {
        InputContext ctx;
        ctx["phi1"] = samples[t];

        double got = I.update(t, ctx);
        double exp = Traits::apply(samples, t);

        if (std::isinf(exp)) {
            EXPECT_TRUE(std::isinf(got));
        }
        else {
            EXPECT_NEAR(got, exp, 1e-9);
        }
    }
}

// Monotonicity according to STL semantics:
//  - G, H → non-increasing
//  - F, O → non-decreasing
//  - P    → no monotonicity constraint
TYPED_TEST(TemporalUnaryTests, MonotonicityIfApplicable) {
    using Op = typename TestFixture::Op;

    std::vector<double> s = { 0.5, 0.2, 1.0, -0.5, 0.3 };

    auto root = make_temporal_unary<Op>();
    DiscreteTimeOnlineInterpreter I(root);
    I.set_ast(root);

    std::vector<double> out;
    for (int t = 0; t < s.size(); ++t) {
        InputContext ctx;
        ctx["phi1"] = s[t];
        out.push_back(I.update(t, ctx));
    }

    if constexpr (std::is_same_v<Op, AlwaysNode> ||
        std::is_same_v<Op, HistoricallyNode>)
    {
        for (size_t i = 1; i < out.size(); ++i)
            EXPECT_LE(out[i], out[i - 1] + 1e-12);
    }
    else if constexpr (std::is_same_v<Op, EventuallyNode> ||
        std::is_same_v<Op, OnceNode>)
    {
        for (size_t i = 1; i < out.size(); ++i)
            EXPECT_GE(out[i], out[i - 1] - 1e-12);
    }
    else {
        SUCCEED(); // PreviousNode
    }
}

// Explicit test for P
TEST(TemporalUnaryExplicitTests, PreviousNodeCorrectness) {
    PNode phi = std::make_shared<VariableNode>("phi1");
    auto root = std::make_shared<PreviousNode>(phi);

    DiscreteTimeOnlineInterpreter I(root);
    I.set_ast(root);

    InputContext ctx;

    ctx["phi1"] = 5.0;
    EXPECT_TRUE(std::isinf(I.update(0, ctx)));

    ctx["phi1"] = 7.0;
    EXPECT_DOUBLE_EQ(I.update(1, ctx), 5.0);

    ctx["phi1"] = -3.0;
    EXPECT_DOUBLE_EQ(I.update(2, ctx), 7.0);
}

//
// ======================================================================
// BINARY TEMPORAL — SINCE (S)
// ======================================================================
//

template<typename Op>
struct SinceTraits {
    static constexpr const char* name = "UnknownSince";
    static constexpr const char* token = "since";
};

template<>
struct SinceTraits<SinceNode> {
    static constexpr const char* name = "SinceNode";
    static constexpr const char* token = "since";   // SYMBOL OPERATOR
};

template<typename Op>
std::shared_ptr<Op> make_since() {
    PNode phi = std::make_shared<VariableNode>("phi1");
    PNode psi = std::make_shared<VariableNode>("phi2");
    return std::make_shared<Op>(phi, psi);
}

template<typename T>
class SinceTests : public ::testing::Test {
public:
    using Op = T;
    using Traits = SinceTraits<T>;
};

using SinceOps = ::testing::Types<SinceNode>;

struct SinceNamePrinter {
    template<typename T>
    static std::string GetName(int) { return SinceTraits<T>::name; }
};

TYPED_TEST_SUITE(SinceTests, SinceOps, SinceNamePrinter);

// 1) Construction
TYPED_TEST(SinceTests, ConstructsNotNull) {
    ASSERT_NE(make_since<typename TestFixture::Op>(), nullptr);
}

// 2) Children
TYPED_TEST(SinceTests, ChildrenLinkedCorrectly) {
    PNode left = std::make_shared<VariableNode>("phi1");
    PNode right = std::make_shared<VariableNode>("phi2");

    auto n = std::make_shared<typename TestFixture::Op>(left, right);

    ASSERT_EQ(n->getChildren().size(), 2u);
    EXPECT_EQ(n->getChildren().at(0), left);
    EXPECT_EQ(n->getChildren().at(1), right);
}

// 3) Name symbol
TYPED_TEST(SinceTests, NameContainsSymbolAndVars) {
    auto root = make_since<typename TestFixture::Op>();
    std::string name = root->getName();

    EXPECT_NE(name.find("phi1"), std::string::npos);
    EXPECT_NE(name.find("phi2"), std::string::npos);
    EXPECT_NE(name.find(TestFixture::Traits::token), std::string::npos);
}

// 4) Recurrence definition
//
// S(0) = psi(0)
// S(t) = max( psi(t), min( phi(t), S(t−1) ) )
//
TYPED_TEST(SinceTests, EvaluationMatchesRecurrence) {
    std::vector<double> phi = { 0.5, -0.2, 0.7, 0.1 };
    std::vector<double> psi = { -0.3, 0.6, -0.4, 0.2 };

    auto root = make_since<typename TestFixture::Op>();
    DiscreteTimeOnlineInterpreter I(root);
    I.set_ast(root);

    double s_prev = -std::numeric_limits<double>::infinity();

    for (int t = 0; t < phi.size(); ++t) {
        InputContext ctx;
        ctx["phi1"] = phi[t];
        ctx["phi2"] = psi[t];

        double got = I.update(t, ctx);

        double exp = (t == 0)
            ? psi[0]
            : std::max(psi[t], std::min(phi[t], s_prev));

        s_prev = exp;

        if (std::isinf(exp)) {
            EXPECT_TRUE(std::isinf(got));
        }
        else {
            EXPECT_NEAR(got, exp, 1e-9);
        }
    }
}