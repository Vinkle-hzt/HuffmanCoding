#pragma once
#include <vector>
#include <string>
#include <queue>
#include <map>

using std::map;
using std::pair;
using std::string;
using std::vector;

/**
 * @brief 哈夫曼树节点结构
 * @author 胡泽涛
 * 
 */
struct HuffmanTreeNode
{
    HuffmanTreeNode(HuffmanTreeNode *left, HuffmanTreeNode *right);
    HuffmanTreeNode(char data, int freq);

    bool isLeaf() const;

    char data;
    int freq;
    HuffmanTreeNode *left;
    HuffmanTreeNode *right;
};

/**
 * @brief 哈夫曼树
 * @author 胡泽涛
 * 
 */
class HuffmanTree
{
private:
    using node = HuffmanTreeNode;

    node *root;
    map<char, string> code;

    void encode();
    void encodeHelp(node *cur, string &pattern);
    void clear(node* cur);

public:
    HuffmanTree(map<char, int> &data);
    ~HuffmanTree();

    /**
     * @brief Get the Coding object
     * 
     * @return map<char, string> huffman code like
     *        {<'a', "00">, <'b', "01">, <'c', "1">}
     */
    map<char, string> &getCoding();
};