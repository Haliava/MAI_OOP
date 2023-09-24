cmake_minimum_required(VERSION 3.21)
project(1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(1 src/main.cpp tests/tests.cpp src/convertTimeTo24h.cpp header/convertTimeTo24h.h)

enable_testing()

target_link_libraries(tests ${GTEST_LIBRARIES})
target_link_libraries(tests pthread)

add_test(NAME BASIC COMMAND tests)