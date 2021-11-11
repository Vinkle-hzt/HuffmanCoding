cmake_minimum_required(VERSION 3.0.0)
project(HuffmanCoding VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE SRCS "src/*.cpp")

add_executable(HuffmanCoding ${SRCS})
include_directories(${PROJECT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
