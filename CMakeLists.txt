cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME uniquePtrLib)

project(${PROJECT_NAME} VERSION 1.0)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/compilerSetup.txt)

add_subdirectory(dependencies/googletest)
add_subdirectory(lib/uniquePtr)
add_subdirectory(lib/main)
add_subdirectory(UnitTest)