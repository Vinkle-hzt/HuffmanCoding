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
    map<string,char> read = readCode(filename+".code");
    map<char,string> read_code;
    for(auto i:read)
    {
        read_code[i.second]=i.first;
    }
    assert(read_code==coding);
}

int main(int argc, char** argv)
{
    if (argc > 1)
        huffman_test(argv[1]);
    else
    {
        huffman_test("../f1.txt");
        huffman_test("../f2.txt");
        huffman_test("../f3.txt");
        huffman_test("../final.txt");
    }
}