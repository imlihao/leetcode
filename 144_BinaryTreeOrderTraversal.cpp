#include <iostream>
#include <queue>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            if (!cur)
            {
                cur = stk.top();
                stk.pop();
            }
            while (cur)
            {
                if (cur->right)
                {
                    stk.push(cur->right);
                }
                res.push_back(cur->val);
                cur = cur->left;
            }
        }
        return res;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            if (!cur)
            {
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
            while (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
        }

        return res;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        TreeNode *cur = root;
        TreeNode *last = nullptr;
        stack<TreeNode *> stk;
        while (cur || !stk.empty())
        {
            while (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            if (!stk.empty())
            {
                cur = stk.top();
                if (cur->right && cur->right != last) //
                {
                    cur = cur->right;
                }
                else
                {
                    res.push_back(cur->val);
                    last = cur;
                    cur = nullptr;
                    stk.pop();
                }
            }
        }
        return res;
    }

    void preOrder(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;
        res.push_back(node->val);
        preOrder(node->left, res);
        preOrder(node->right, res);
    }

    void inOrder(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;
        inOrder(node->left, res);
        res.push_back(node->val);
        inOrder(node->right, res);
    }

    void postOrder(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;
        postOrder(node->left, res);
        postOrder(node->right, res);
        res.push_back(node->val);
    }
};

int main()
{
    TreeNode a(1), b(2), c(3);
    a.right = &b;
    b.left = &c;
    auto res = Solution().postorderTraversal(&a);
    for (auto &rr : res)
    {
        cout << rr << " ";
    }
    cout << endl;
    system("pause");
}
