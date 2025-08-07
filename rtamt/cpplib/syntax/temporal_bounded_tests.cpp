// file: temporal_ops_typed_tests.cpp

#include <gtest/gtest.h>
#include <cmath>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <type_traits>

// ===== AST base + interpreter
#include <node/abstract_node.hpp>
#include <abstract_discrete_time_online_interpreter.hpp>

// ===== Unary temporal nodes (symbolic: G F H O P)
#include <node/ltl/always.hpp>        // G
#include <node/ltl/eventually.hpp>    // F
#include <node/ltl/historically.hpp>  // H
#include <node/ltl/once.hpp>          // O
#include <node/ltl/previous.hpp>      // P

// ===== Binary temporal node: Since (unbounded)
// NOTE: getName() for Since prints "... since ...", not "S"
#include <node/ltl/since.hpp>

// ===== Bounded temporal nodes (Interval-based, from your stl path)
#include <node/stl/timed_historically.hpp>
#include <node/stl/timed_once.hpp>
#include <node/stl/timed_since.hpp>
#include <node/stl/timed_precedes.hpp>

// ===== Variable node
#include <node/ltl/variable.hpp>

// ===== Interpreter front
#include <time_interpreter.hpp>

using namespace stl_library;

// Typedefs come from your headers:
//   using PNode   = std::shared_ptr<AbstractNode>;
//   using DataSet = std::map<std::string, double>;
using PNode = std::shared_ptr<AbstractNode>;
using InputContext = DataSet;

// =====================================================================
// UNARY TEMPORAL TRAITS — OPERATOR SYMBOL TOKENS: G F H O P
// =====================================================================

template <typename Op>
struct TemporalUnaryTraits {
    static constexpr const char* name = "UnknownTemporalUnary";
    static constexpr const char* token = "";   // substring expected in getName()
    static double apply(const std::vector<double>& h, int t) { return 0.0; }
};

/// G φ = min(0..t)
template<>
struct TemporalUnaryTraits<AlwaysNode> {
    static constexpr const char* name = "AlwaysNode";
    static constexpr const char* token = "G";
    static double apply(const std::vector<double>& h, int t) {
        double r = h[0];
        for (int i = 1; i <= t; ++i) r = std::min(r, h[i]);
        return r;
    }
};

/// F φ = max(0..t)
template<>
struct TemporalUnaryTraits<EventuallyNode> {
    static constexpr const char* name = "EventuallyNode";
    static constexpr const char* token = "F";
    static double apply(const std::vector<double>& h, int t) {
        double r = h[0];
        for (int i = 1; i <= t; ++i) r = std::max(r, h[i]);
        return r;
    }
};

/// H φ = min(0..t)
template<>
struct TemporalUnaryTraits<HistoricallyNode> {
    static constexpr const char* name = "HistoricallyNode";
    static constexpr const char* token = "H";
    static double apply(const std::vector<double>& h, int t) {
        double r = h[0];
        for (int i = 1; i <= t; ++i) r = std::min(r, h[i]);
        return r;
    }
};

/// O φ = max(0..t)
template<>
struct TemporalUnaryTraits<OnceNode> {
    static constexpr const char* name = "OnceNode";
    static constexpr const char* token = "O";
    static double apply(const std::vector<double>& h, int t) {
        double r = h[0];
        for (int i = 1; i <= t; ++i) r = std::max(r, h[i]);
        return r;
    }
};

/// P φ(t) = φ(t−1), with P φ(0) = +∞  (matches prev_in = +∞)
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

// =====================================================================
// UNARY TEMPORAL TYPED FIXTURE
// =====================================================================

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
    return std::make_shared<Op>(std::make_shared<VariableNode>("phi1"));
}

// ---------------- UNARY TESTS ----------------

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

    for (int t = 0; t < static_cast<int>(samples.size()); ++t) {
        InputContext ctx; ctx["phi1"] = samples[t];

        double got = I.update(t, ctx);
        double exp = Traits::apply(samples, t);

        if (std::isinf(exp)) EXPECT_TRUE(std::isinf(got));
        else                 EXPECT_NEAR(got, exp, 1e-9);
    }
}

// Monotonicity from STL robustness:
//  - G/H → non-increasing
//  - F/O → non-decreasing
//  - P    → no monotonicity constraint
TYPED_TEST(TemporalUnaryTests, MonotonicityIfApplicable) {
    using Op = typename TestFixture::Op;

    std::vector<double> s = { 0.5, 0.2, 1.0, -0.5, 0.3 };

    auto root = make_temporal_unary<Op>();
    DiscreteTimeOnlineInterpreter I(root);
    I.set_ast(root);

    std::vector<double> out;
    for (int t = 0; t < static_cast<int>(s.size()); ++t) {
        InputContext ctx; ctx["phi1"] = s[t];
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

// Explicit P behavior
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

// =====================================================================
// BINARY TEMPORAL — SINCE (UNBOUNDED)
// NOTE: getName() for Since uses "since", per your format.
// =====================================================================

template<typename Op>
struct SinceTraits {
    static constexpr const char* name = "UnknownSince";
    static constexpr const char* token = "since";
};

template<>
struct SinceTraits<SinceNode> {
    static constexpr const char* name = "SinceNode";
    static constexpr const char* token = "since"; // <-- per your getName()
};

template<typename Op>
std::shared_ptr<Op> make_since() {
    return std::make_shared<Op>(
        std::make_shared<VariableNode>("phi1"),
        std::make_shared<VariableNode>("phi2"));
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

// --- Unbounded Since tests ---

TYPED_TEST(SinceTests, ConstructsNotNull) {
    ASSERT_NE(make_since<typename TestFixture::Op>(), nullptr);
}

TYPED_TEST(SinceTests, ChildrenLinkedCorrectly) {
    PNode left = std::make_shared<VariableNode>("phi1");
    PNode right = std::make_shared<VariableNode>("phi2");
    auto n = std::make_shared<typename TestFixture::Op>(left, right);

    ASSERT_EQ(n->getChildren().size(), 2u);
    EXPECT_EQ(n->getChildren().at(0), left);
    EXPECT_EQ(n->getChildren().at(1), right);
}

TYPED_TEST(SinceTests, NameContainsTokenAndVars) {
    auto root = make_since<typename TestFixture::Op>();
    std::string name = root->getName();

    EXPECT_NE(name.find("phi1"), std::string::npos);
    EXPECT_NE(name.find("phi2"), std::string::npos);
    EXPECT_NE(name.find(TestFixture::Traits::token), std::string::npos); // "since"
}

// Recurrence (online, unbounded):
// s(0) = psi(0)
// s(t) = max( psi(t), min( phi(t), s(t-1) ) )
TYPED_TEST(SinceTests, EvalMatchesRecurrence) {
    std::vector<double> phi = { 0.5, -0.2, 0.7, 0.1 };
    std::vector<double> psi = { -0.3, 0.6, -0.4, 0.2 };

    auto root = make_since<typename TestFixture::Op>();
    DiscreteTimeOnlineInterpreter I(root);
    I.set_ast(root);

    double s_prev = -std::numeric_limits<double>::infinity();

    for (int t = 0; t < static_cast<int>(phi.size()); ++t) {
        InputContext ctx; ctx["phi1"] = phi[t]; ctx["phi2"] = psi[t];

        double got = I.update(t, ctx);

        double exp = (t == 0)
            ? psi[0]
            : std::max(psi[t], std::min(phi[t], s_prev));

        s_prev = exp;

        if (std::isinf(exp)) EXPECT_TRUE(std::isinf(got));
        else                 EXPECT_NEAR(got, exp, 1e-9);
    }
}

// =====================================================================
// BOUNDED TEMPORAL OPERATORS (Interval-based, prefix-window semantics)
//   - TimedHistoricallyNode     : prefix MIN over first W+1 samples
//   - TimedOnceNode             : prefix MAX over first W+1 samples
//   - TimedSinceNode            : bounded since (per your inner loops)
//   - TimedPrecedesNode         : bounded precedes (per your inner loops)
// =====================================================================

template<typename T>
class BoundedTemporalTests : public ::testing::Test {
public:
    using Op = T;
};

// NOTE: If your actual classes are Stl*BoundedNode instead of Timed*Node,
// replace the types below accordingly.
using BoundedOps = ::testing::Types<
    TimedHistoricallyNode,
    TimedOnceNode,
    TimedSinceNode,
    TimedPrecedesNode
>;

struct BoundedTemporalNamePrinter {
    template<typename T> static std::string GetName(int) {
        return typeid(T).name();
    }
};

TYPED_TEST_SUITE(BoundedTemporalTests, BoundedOps, BoundedTemporalNamePrinter);

// Helpers to build bounded nodes
template<typename Op>
std::shared_ptr<Op> make_bounded_unary(const Interval& itv) {
    return std::make_shared<Op>(std::make_shared<VariableNode>("phi1"), itv);
}

template<typename Op>
std::shared_ptr<Op> make_bounded_binary(const Interval& itv) {
    return std::make_shared<Op>(
        std::make_shared<VariableNode>("phi1"),
        std::make_shared<VariableNode>("phi2"),
        itv);
}

// ---- 1) Construction ----
TYPED_TEST(BoundedTemporalTests, ConstructsNotNull) {
    Interval itv(2, 4);
    if constexpr (std::is_base_of_v<UnaryNode, typename TestFixture::Op>) {
        auto n = make_bounded_unary<typename TestFixture::Op>(itv);
        ASSERT_NE(n, nullptr);
    }
    else {
        auto n = make_bounded_binary<typename TestFixture::Op>(itv);
        ASSERT_NE(n, nullptr);
    }
}

// ---- 2) Children ----
TYPED_TEST(BoundedTemporalTests, ChildrenCorrect) {
    Interval itv(2, 4);

    if constexpr (std::is_base_of_v<UnaryNode, typename TestFixture::Op>) {
        PNode phi = std::make_shared<VariableNode>("phi1");
        auto n = std::make_shared<typename TestFixture::Op>(phi, itv);
        ASSERT_EQ(n->getChildren().size(), 1u);
        EXPECT_EQ(n->getChildren().at(0), phi);
    }
    else {
        PNode l = std::make_shared<VariableNode>("phi1");
        PNode r = std::make_shared<VariableNode>("phi2");
        auto n = std::make_shared<typename TestFixture::Op>(l, r, itv);
        ASSERT_EQ(n->getChildren().size(), 2u);
        EXPECT_EQ(n->getChildren().at(0), l);
        EXPECT_EQ(n->getChildren().at(1), r);
    }
}

// ---- 3) Interval stored ----
TYPED_TEST(BoundedTemporalTests, IntervalStoredCorrectly) {
    Interval itv(2, 4);
    if constexpr (std::is_base_of_v<UnaryNode, typename TestFixture::Op>) {
        auto n = make_bounded_unary<typename TestFixture::Op>(itv);
        EXPECT_EQ(n->getInterval().getBegin(), 2);
        EXPECT_EQ(n->getInterval().getEnd(), 4);
    }
    else {
        auto n = make_bounded_binary<typename TestFixture::Op>(itv);
        EXPECT_EQ(n->getInterval().getBegin(), 2);
        EXPECT_EQ(n->getInterval().getEnd(), 4);
    }
}

// ---- 4) Evaluation: EXACT implementation semantics ----
// Based on the update(...) loops you shared for bounded nodes.
TYPED_TEST(BoundedTemporalTests, EvaluationMatchesImplementation) {
    Interval itv(2, 4);
    const int W = itv.getEnd() - itv.getBegin();   // window length: W

    // Test inputs (longer than the window to exercise "fixed prefix" behavior)
    std::vector<double> phi = { 1.0, -2.0,  5.0, -1.0,  4.0 };
    std::vector<double> psi = { 0.3,  0.1, -0.4,  2.0, -3.0 };

    std::shared_ptr<AbstractNode> root;
    if constexpr (std::is_same_v<typename TestFixture::Op, TimedHistoricallyNode>) {
        root = make_bounded_unary<TimedHistoricallyNode>(itv);
    }
    else if constexpr (std::is_same_v<typename TestFixture::Op, TimedOnceNode>) {
        root = make_bounded_unary<TimedOnceNode>(itv);
    }
    else if constexpr (std::is_same_v<typename TestFixture::Op, TimedSinceNode>) {
        root = make_bounded_binary<TimedSinceNode>(itv);
    }
    else if constexpr (std::is_same_v<typename TestFixture::Op, TimedPrecedesNode>) {
        root = make_bounded_binary<TimedPrecedesNode>(itv);
    }

    DiscreteTimeOnlineInterpreter I(root);
    I.set_ast(root);

    std::vector<double> Hphi; // left stream
    std::vector<double> Hpsi; // right stream

    for (int t = 0; t < static_cast<int>(phi.size()); ++t) {
        Hphi.push_back(phi[t]);
        Hpsi.push_back(psi[t]);

        InputContext ctx; ctx["phi1"] = phi[t]; ctx["phi2"] = psi[t];

        double got = I.update(t, ctx);
        double exp = 0.0;

        // ===== EXACT bounded semantics (prefix windows) =====
        if constexpr (std::is_same_v<typename TestFixture::Op, TimedHistoricallyNode>) {
            exp = +std::numeric_limits<double>::infinity();
            for (int i = 0; i <= W && i < static_cast<int>(Hphi.size()); ++i)
                exp = std::min(exp, Hphi[i]);
        }
        else if constexpr (std::is_same_v<typename TestFixture::Op, TimedOnceNode>) {
            exp = -std::numeric_limits<double>::infinity();
            for (int i = 0; i <= W && i < static_cast<int>(Hphi.size()); ++i)
                exp = std::max(exp, Hphi[i]);
        }
        else if constexpr (std::is_same_v<typename TestFixture::Op, TimedSinceNode>) {
            // for i = 0..W: right = psi[i], left = min(phi[j]) for j in [i+1..end]
            exp = -std::numeric_limits<double>::infinity();
            for (int i = 0; i <= W && i < static_cast<int>(Hpsi.size()); ++i) {
                double right = Hpsi[i];
                double left = +std::numeric_limits<double>::infinity();
                for (int j = i + 1; j <= itv.getEnd() && j < static_cast<int>(Hphi.size()); ++j)
                    left = std::min(left, Hphi[j]);
                exp = std::max(exp, std::min(left, right));
            }
        }
        else if constexpr (std::is_same_v<typename TestFixture::Op, TimedPrecedesNode>) {
            // for i = begin..end: right = psi[i], left = min(phi[j]) for j in [0..i-1]
            exp = -std::numeric_limits<double>::infinity();
            for (int i = itv.getBegin(); i <= itv.getEnd() && i < static_cast<int>(Hpsi.size()); ++i) {
                double right = Hpsi[i];
                double left = +std::numeric_limits<double>::infinity();
                for (int j = 0; j < i && j < static_cast<int>(Hphi.size()); ++j)
                    left = std::min(left, Hphi[j]);
                exp = std::max(exp, std::min(left, right));
            }
        }

        EXPECT_NEAR(got, exp, 1e-9)
            << "\nOperator: " << typeid(typename TestFixture::Op).name()
            << "\nt=" << t
            << "\nphi=" << phi[t]
            << "\npsi=" << psi[t]
            << "\nexpected=" << exp << "  actual=" << got
            << "\nwindow=[0.." << W << "], interval=[" << itv.getBegin() << "," << itv.getEnd() << "]";
    }
}