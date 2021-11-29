#include "HuffmanTree.h"
using namespace std;

struct cmp
{
    bool operator()(HuffmanTreeNode *lhs, HuffmanTreeNode *rhs) const
    {
        return lhs->freq > rhs->freq;
    }
};

HuffmanTreeNode::HuffmanTreeNode(HuffmanTreeNode *left, HuffmanTreeNode *right)
    : freq(left->freq + right->freq), left(left), right(right) {}

HuffmanTreeNode::HuffmanTreeNode(char data, int freq)
    : data(data), freq(freq), left(nullptr), right(nullptr) {}

bool HuffmanTreeNode::isLeaf() const
{
    return !left && !right;
}

HuffmanTree::HuffmanTree(map<char, int> &data)
{
    priority_queue<node *, vector<node *>, cmp> q;
    for (const auto &p : data)
        q.push(new node(p.first, p.second));

    if (q.empty())
    {
        root = nullptr;
        return;
    }

    if (q.size() == 1)
    {
        root = q.top();
        q.pop();
        code[root->data] = "0";
        return;
    }

    while (q.size() > 1)
    {
        node *n1 = q.top();
        q.pop();
        node *n2 = q.top();
        q.pop();
        node *n3 = new node(n1, n2);
        q.push(n3);
    }
    root = q.top();
    q.pop();
    encode();
}

void HuffmanTree::encode()
{
    string pattern;
    encodeHelp(root, pattern);
}

void HuffmanTree::encodeHelp(HuffmanTreeNode *cur, string &pattern)
{
    if (cur->isLeaf())
    {
        code[cur->data] = pattern;
        return;
    }

    pattern.push_back('0');
    encodeHelp(cur->left, pattern);
    pattern.pop_back();

    pattern.push_back('1');
    encodeHelp(cur->right, pattern);
    pattern.pop_back();
}

map<char, string> &HuffmanTree::getCoding()
{
    return code;
}

HuffmanTree::~HuffmanTree()
{
    clear(root);
}

void HuffmanTree::clear(node* cur)
{
    if (!cur)
        return;
    node* tmp = cur;
    clear(cur->left);
    clear(cur->right);
    delete cur;
}
