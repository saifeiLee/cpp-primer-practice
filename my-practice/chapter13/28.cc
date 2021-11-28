#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class BinStrTree;
class TreeNode
{
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode() : value("test"), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &);
    TreeNode &operator=(const TreeNode &);
    ~TreeNode();

    void print();
};

TreeNode::TreeNode(const TreeNode &other) : value(other.value), count(other.count)
{
    if (other.left)
    {
        left = new TreeNode(*other.left);
    }
    if (other.right)
    {
        right = new TreeNode(*other.right);
    }
}

TreeNode &TreeNode::operator=(const TreeNode &t)
{
    auto new_left = new TreeNode(*t.left);
    auto new_right = new TreeNode(*t.right);
    delete left;
    delete right;
    left = new_left;
    right = new_right;
    value = t.value;
    count = t.count;
    return *this;
}

TreeNode::~TreeNode()
{
    delete left;
    delete right;
}

void TreeNode::print()
{
    cout << value << " " << count << endl;
}

class BinStrTree
{
private:
    TreeNode *root;

public:
    BinStrTree() : root(nullptr) {}
    ~BinStrTree()
    {
        delete root;
    }
    BinStrTree(const BinStrTree &);
    BinStrTree &operator=(const BinStrTree &);
};

BinStrTree::BinStrTree(const BinStrTree &other)
{
    if (other.root)
    {
        root = new TreeNode(*other.root);
    }
}
BinStrTree &BinStrTree::operator=(const BinStrTree &t)
{
    auto new_root = new TreeNode(*t.root);
    delete root;
    root = new_root;
    return *this;
}

int main()
{
    TreeNode t1;
    TreeNode t2 = t1;
    t1.print();
    t2.print();
    return 0;

    // TreeNode t2;
    // t2.value = "hello";
}