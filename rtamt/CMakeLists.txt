cmake_minimum_required(VERSION 3.12)

set(RTAMAT_CPPLIB_DIR ${CMAKE_SOURCE_DIR}/lib/)
add_subdirectory(cpplib/syntax)
#add_subdirectory(cpplib/spec)
add_subdirectory(cpplib/semantics)
#add_subdirectory(cpplib/stl)