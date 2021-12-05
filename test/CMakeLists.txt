cmake_minimum_required(VERSION 3.0.0)

project(HuffmanTest)

add_executable(decode_test decode_test.cpp)
target_link_libraries(decode_test Huffmanlib)

add_executable(read_test read_test.cpp)
target_link_libraries(read_test Huffmanlib)

add_test(decode_test_1 decode_test "../f1.txt")
add_test(decode_test_2 decode_test "../f2.txt")
add_test(decode_test_3 decode_test "../f3.txt")
add_test(decode_test_4 decode_test "../final.txt")
add_test(read_test_1 read_test "../f1.txt")
add_test(read_test_2 read_test "../f2.txt")
add_test(read_test_3 read_test "../f3.txt")
add_test(read_test_4 read_test "../final.txt")

