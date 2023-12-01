cmake_minimum_required(VERSION 3.1)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           main
  SOURCE_DIR        "/mnt/c/Users/La Cretura/Desktop/PRJ/MAI/course 2/oop/3_Lab/build/googletest-src"
  BINARY_DIR        "/mnt/c/Users/La Cretura/Desktop/PRJ/MAI/course 2/oop/3_Lab/build/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
