cmake_minimum_required(VERSION 3.12)
project(rtamt_stl_syntax)

## Declare a C++ library
add_library(${PROJECT_NAME}
	STATIC
		ast/visitor/abstract_ast_visitor.hpp
		ast/visitor/abstract_ast_visitor.cpp
		ast/visitor/ltl/ast_visitor.hpp
		ast/visitor/stl/ast_visitor.hpp
		ast/visitor/ltl/ast_visitor.cpp
		ast/visitor/stl/ast_visitor.cpp
		node/abstract_node.hpp
		node/binary_node.hpp
		node/unary_node.hpp
		node/leaf_node.hpp
		node/abstract_node.cpp
		node/binary_node.cpp
		node/unary_node.cpp
		node/leaf_node.cpp
		node/arithmetic/abs.hpp
		node/arithmetic/addition.hpp
		node/arithmetic/division.hpp
		node/arithmetic/exp.hpp
		node/arithmetic/ln.hpp
		node/arithmetic/log.hpp
		node/arithmetic/multiplication.hpp
		node/arithmetic/negate.hpp
		node/arithmetic/pow.hpp
		node/arithmetic/sqrt.hpp
		node/arithmetic/subtraction.hpp
		node/ltl/always.hpp
		node/ltl/conjunction.hpp
		node/ltl/constant.hpp
		node/ltl/disjunction.hpp
		node/ltl/eventually.hpp
		node/ltl/fall.hpp
		node/ltl/historically.hpp
		node/ltl/iff.hpp
		node/ltl/implies.hpp
		node/ltl/neg.hpp
		node/ltl/next.hpp
		node/ltl/once.hpp
		node/ltl/predicate.hpp
		node/ltl/previous.hpp
		node/ltl/rise.hpp
		node/ltl/since.hpp
		node/ltl/strong_next.hpp
		node/ltl/strong_previous.hpp
		node/ltl/until.hpp
		node/ltl/variable.hpp
		node/ltl/xor.hpp
		node/stl/timed_always.hpp
		node/stl/timed_eventually.hpp
		node/stl/timed_historically.hpp
		node/stl/timed_once.hpp
		node/stl/timed_precedes.hpp
		node/stl/timed_since.hpp
		node/stl/timed_until.hpp
		interval/interval.hpp
		node/abstract_node.cpp
		node/binary_node.cpp
		node/unary_node.cpp
		node/leaf_node.cpp
		node/arithmetic/abs.cpp
		node/arithmetic/addition.cpp
		node/arithmetic/division.cpp
		node/arithmetic/exp.cpp
		node/arithmetic/ln.cpp
		node/arithmetic/log.cpp
		node/arithmetic/multiplication.cpp
		node/arithmetic/negate.cpp
		node/arithmetic/pow.cpp
		node/arithmetic/sqrt.cpp
		node/arithmetic/subtraction.cpp
		node/ltl/always.cpp
		node/ltl/conjunction.cpp
		node/ltl/constant.cpp
		node/ltl/disjunction.cpp
		node/ltl/eventually.cpp
		node/ltl/fall.cpp
		node/ltl/historically.cpp
		node/ltl/iff.cpp
		node/ltl/implies.cpp
		node/ltl/neg.cpp
		node/ltl/next.cpp
		node/ltl/once.cpp
		node/ltl/predicate.cpp
		node/ltl/previous.cpp
		node/ltl/rise.cpp
		node/ltl/since.cpp
		node/ltl/strong_next.cpp
		node/ltl/strong_previous.cpp
		node/ltl/until.cpp
		node/ltl/variable.cpp
		node/ltl/xor.cpp
		node/stl/timed_always.cpp
		node/stl/timed_eventually.cpp
		node/stl/timed_historically.cpp
		node/stl/timed_once.cpp
		node/stl/timed_precedes.cpp
		node/stl/timed_since.cpp
		node/stl/timed_until.cpp
		interval/interval.cpp
		
)

set(SYNTAX_DIR ${PROJECT_SOURCE_DIR} CACHE PATH "Global data directory")
target_include_directories(${PROJECT_NAME}
	PUBLIC ${PROJECT_SOURCE_DIR}
)

add_executable(ast_test main.cpp)
# link the 'my_program_code' library into the main executable
target_link_libraries(ast_test 
	PUBLIC 
		rtamt_stl_syntax
		rtamt_stl_semantics
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent) 
FetchContent_Declare( 
	googletest 
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip 
) 
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(cpp_stl_tests tests.cpp) 
target_link_libraries(cpp_stl_tests GTest::gtest_main rtamt_stl_syntax rtamt_stl_semantics)

include(GoogleTest)
gtest_discover_tests(cpp_stl_tests)