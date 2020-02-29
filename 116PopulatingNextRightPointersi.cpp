//116. Populating Next Right Pointers in Each Node
/**
 *  1.参考递归方法打印树的某层 o(1+2+4+..+n)
 *  DFS条件为level满足条件的，先左后右的话访问targetLevel时按顺序的
 * 
 *  2.利用本层已有的信息，链接下一层 o(n)
 * */
// Definition for a Node.
#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        // if (!root)
        //     return NULL;
        // int level = 1;
        // auto t = new Node();
        // Node **tt = &t;
        // *tt = nullptr;
        // delete t;
        // while (DFSfind(root, tt, level++))
        // {
        //     *tt = nullptr;
        // }
        connect2(root);
        return root;
    }

    bool DFSfind(Node *root, Node **t, int level)
    {
        if (!root && level < 1)
            return false;
        if (!root)
            return true;
        if (level < 1)
            return true;
        if (level == 1)
        {
            if (!(*t))
            {
                *t = root;
            }
            else
            {
                (*t)->next = root;
                *t = root;
            }
        }
        bool a = DFSfind(root->left, t, level - 1);
        bool b = DFSfind(root->right, t, level - 1);
        return a & b;
    }

    void connect2(Node *root)
    {
        if (!root)
            return;
        if (root->left)
        {
            root->left->next = root->right;
        }
        if (root->right && root->next)
        {
            root->right->next = root->next->left;
        }
        connect2(root->left);
        connect2(root->right);
    }
};
int main()
{
    Node a(7), b(6), c(5), d(4), e(3, &b, &a, nullptr), f(2, &d, &c, NULL), g(1, &f, &e, NULL);
    Solution().connect(&g);
}
