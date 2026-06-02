cmake_minimum_required(VERSION 3.12)
project(rtamt_stl_tests)

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

add_executable(cpp_stl_tests 
	nontemporal_unary_op_tests.cpp
	nontemporal_binary_op_tests.cpp
	temporal_bounded_tests.cpp
	temporal_unbounded_tests.cpp
) 
target_link_libraries(cpp_stl_tests GTest::gtest_main rtamt_stl_syntax rtamt_stl_semantics)

include(GoogleTest)
gtest_discover_tests(cpp_stl_tests)