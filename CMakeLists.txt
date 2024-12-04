cmake_minimum_required(VERSION 3.20)
project(hamming_code)

set(CMAKE_CXX_STANDARD 14)
option(BUILD_SHARED_LIBS "Build is done using shared libs" ON)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(hamming src/HammingCode.cpp)
add_executable(hamming_code main.cpp)
target_link_libraries(hamming_code PRIVATE hamming)
