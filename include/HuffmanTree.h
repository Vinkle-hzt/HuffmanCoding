#pragma once
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::pair;
using std::string;
using std::map;

class HuffmanTreeNode
{
    public:
    
    private:

};

class HuffmanTree
{
private:
    /*
    */
public:
    HuffmanTree(map<char, int> &data);
    ~HuffmanTree();

    /**
     * @brief Get the Coding object
     * 
     * @return map<char, string> huffman code like
     *        {<'a', "00">, <'b', "01">, <'c', "1">}
     */
    map<char, string> getCoding() const;
};