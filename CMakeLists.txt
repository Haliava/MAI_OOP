cmake_minimum_required(VERSION 3.21)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(include)
include_directories(src)
include_directories(test)

add_executable(lab1
        src/main.cpp include/convertTimeTo24h.h src/convertTimeTo24h.cpp src/main.cpp)

enable_testing()

add_executable(test1 test/tests.cpp)
target_link_libraries(test1 gtest_main)
add_test(NAME BASIC COMMAND test1)

