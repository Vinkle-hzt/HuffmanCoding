#include "HuffmanTree.h"
#include "FileIO.h"
#include <iostream>
#include <cassert>
using namespace std;

void huffman_test(string filename)
{
    string words = readFromFile(filename);
    auto freq = getFrequency(words);
    HuffmanTree ht(freq);
    auto coding = ht.getCoding();
    writeToBinary(filename, coding);
    writeCode(filename + ".code", coding);
    string decode = decodingFile(filename + ".huf", filename + ".code");
    assert(decode == words);
}

int main(int argc, char** argv)
{
    assert(argc == 2);
    if (argc > 1)
        huffman_test(argv[1]);
}