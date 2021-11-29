#include "HuffmanTree.h"
#include "FileIO.h"
#include <iostream>
#include <cassert>
using namespace std;

void huffman_test(string filename)
{
    string words = readFromFile(filename);
    cout << "open " << filename << "\n";
    cout << words << "\n";
    auto freq = getFrequency(words);
    HuffmanTree ht(freq);
    auto coding = ht.getCoding();
    cout << "binary coding: \n" << get01Text(words, coding) << endl;
    writeToBinary(filename, coding);
    writeCode(filename + ".code", coding);
    string decode = decodingFile(filename + ".huf", filename + ".code");
    cout << "decode words:\n" << decode << endl;
    assert(decode == words);
}

int main(int argc, char** argv)
{
    // ctest
    if (argc > 1)
        huffman_test(argv[1]);
    else
    {
        huffman_test("../f1.txt");
        huffman_test("../f2.txt");
        huffman_test("../f3.txt");
    }
}