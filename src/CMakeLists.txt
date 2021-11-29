cmake_minimum_required(VERSION 3.0.0)

project(Huffmanlib)

set(SRCS fileIO.cpp HuffmanTree.cpp menu.cpp)

add_library(Huffmanlib ${SRCS})

target_include_directories(Huffmanlib PUBLIC ../include)