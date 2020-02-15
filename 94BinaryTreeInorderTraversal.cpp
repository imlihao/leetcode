#include <iostream>
#include <map>
#include <queue>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        stack<TreeNode *> stk;
        auto p = root;
        while (p != nullptr || !stk.empty())
        {
            while (p != nullptr)
            {
                stk.push(p);
                p = p->left;
            }
            if (!stk.empty())
            {
                auto t = stk.top();
                vec.push_back(t->val);
                p = t->right;
                stk.pop();
            }
        }
        return vec;
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        stack<TreeNode *> stk;
        auto p = root;
        while (p != nullptr || !stk.empty())
        {
            while (p != nullptr)
            {
                stk.push(p);
                vec.push_back(p->val);
                p = p->left;
            }
            if (!stk.empty())
            {
                auto t = stk.top();
                p = t->right;
                stk.pop();
            }
        }
        return vec;
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        stack<TreeNode *> stk;
        auto p = root;
        while (p != nullptr || !stk.empty())
        {
            while (p != nullptr)
            {
                stk.push(p);
                p = p->left;
            }
            if (!stk.empty())
            {
                auto t = stk.top();
                vec.push_back(t->val);
                p = t->right;
                stk.pop();
            }
        }
        return vec;
    } 

private:
    void inorder(TreeNode *root, vector<int> &vec)
    {
        if (root == nullptr)
            return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
};
int main()
{
    TreeNode a(1), b(2), c(3);
    a.right = &b;
    b.left = &c;
    Solution slu;
    slu.inorderTraversal(&a);
    system("pause");
    return 0;
}