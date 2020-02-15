#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    void recoverTree(TreeNode *root)
    {
        vector<TreeNode *> nodeVec;
        vector<TreeNode *> tmp;
        // this->inOrder(root, &nodeVec);
        stack<TreeNode *> stk;
        stk.push(root);
        auto last = root;
        while (!stk.empty())
        {
            auto top = stk.top();
            if (top->left != nullptr && top->left != last && top->right != last)
            {
                stk.push(top->left);
            }
            else if (top->right != nullptr && top->right != last)
            {
                nodeVec.push_back(top);
                stk.push(top->right);
            }
            else
            {
                if (top->right != last)
                {
                    nodeVec.push_back(top);
                }
                last = top;
                stk.pop();
            }
        }
        TreeNode a(INT_MIN);
        TreeNode b(INT_MAX);
        nodeVec.insert(nodeVec.begin(), &a);
        nodeVec.push_back(&b);
        // int order = 0;
        // for (int i = 0; i < 3; i++)
        // {
        //     if (nodeVec[i]->val < nodeVec[i + 1]->val)
        //     {
        //         o rder += 1;
        //     }
        // }
        for (int i = 1; i < nodeVec.size() - 1; i++)
        {
            //if(order<2)
            if (!(nodeVec[i - 1]->val < nodeVec[i]->val && nodeVec[i]->val < nodeVec[i + 1]->val))
            {
                tmp.push_back(nodeVec[i]);
            }
        }
        swap(tmp[0]->val, tmp[tmp.size() - 1]->val);
    }
    void inOrder(TreeNode *root, vector<TreeNode *> *vec)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->left, vec);
        vec->push_back(root);
        inOrder(root->right, vec);
    }
};
int main()
{
    Solution slu;
    TreeNode a(1), b(2), c(3), d(2);
    a.left = &c;
    c.right = &b;
    //c.left = &d;
    slu.recoverTree(&a);
    vector<TreeNode *> stk;
    stk.push_back(&a);
    // std::cout << "[";
    // bool hasE = true;
    // int ly = 1;
    // while (hasE)
    // {
    //     hasE = false;
    //     for (int i = 0; i < ly; i++)
    //     {
    //         if (stk[i] != nullptr)
    //             cout << stk[i]->val << ",";
    //         else
    //             cout << "NULL"
    //                  << ",";
    //         stk.push_back(stk[i]->left);
    //         stk.push_back(stk[i]->right);
    //         if ((stk[i]->left != NULL && (stk[i]->left->left != NULL || stk[i]->left->right != NULL)) || (stk[i]->right != NULL && (stk[i]->right->left != NULL || stk[i]->right->right != NULL)))
    //         {
    //             hasE = true;
    //         }
    //     }
    //     stk.erase(stk.begin(), stk.begin() + ly);
    //     ly *= 2;
    // }
    // std::cout << "]";
    // cout << (&c)->left << endl
    //      << (c.left != nullptr) << endl;
    system("pause");
    return 0;
}