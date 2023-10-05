cmake_minimum_required(VERSION 3.21)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(include)
include_directories(src)
include_directories(test)

add_executable(lab2
        src/main.cpp include/Three.h src/Three.cpp src/Array.cpp include/Array.h)

enable_testing()

add_executable(test1 test/test.cpp)
target_link_libraries(test1 gtest_main)
add_test(NAME BASIC COMMAND test1)

