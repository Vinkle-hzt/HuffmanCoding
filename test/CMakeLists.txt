cmake_minimum_required(VERSION 3.0.0)

project(HuffmanTest)

add_executable(${PROJECT_NAME} huffman_test.cpp)

target_link_libraries(HuffmanTest Huffmanlib)

add_test(decode_test_1 ${PROJECT_NAME} "../f1.txt")
add_test(decode_test_2 ${PROJECT_NAME} "../f2.txt")
add_test(decode_test_3 ${PROJECT_NAME} "../f3.txt")
