cmake_minimum_required(VERSION 3.0.0)
project(HuffmanCoding VERSION 0.1.0)

include(CTest)
enable_testing()

file(COPY file/f1.txt DESTINATION ${PROJECT_BINARY_DIR})
file(COPY file/f2.txt DESTINATION ${PROJECT_BINARY_DIR})
file(COPY file/f3.txt DESTINATION ${PROJECT_BINARY_DIR})

add_subdirectory(src)
add_subdirectory(test)

add_executable(HuffmanCoding src/main.cpp)
target_link_libraries(HuffmanCoding Huffmanlib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
