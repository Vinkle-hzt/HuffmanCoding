#pragma once
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::pair;
using std::string;
using std::map;

/**
 * @brief 
 * @author 胡泽涛
 * 
 */
class HuffmanTreeNode
{
    public:
        HuffmanTreeNode(int freq, HuffmanTreeNode* left, HuffmanTreeNode* right);

    private:
        char data;
        int frequency;
        HuffmanTreeNode* left;
        HuffmanTreeNode* right;
};

/**
 * @brief 
 * @author 胡泽涛
 * 
 */
class HuffmanTree
{
private:
    /*
    */
   map<char, string> code;
public:
    HuffmanTree(map<char, int> &data);
    ~HuffmanTree();

    /**
     * @brief Get the Coding object
     * 
     * @return map<char, string> huffman code like
     *        {<'a', "00">, <'b', "01">, <'c', "1">}
     */
    const map<char, string>& getCoding() const;
};