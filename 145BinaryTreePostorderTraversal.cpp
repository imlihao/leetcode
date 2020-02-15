#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> stk;
        stk.push(root);
        TreeNode *lastPop;
        if(root==nullptr)
            return ans;
        while (!stk.empty())
        {
            auto top = stk.top();
            if ((!top->right && !top->left) || (lastPop && (top->left == lastPop || top->right == lastPop)))
            {
                ans.push_back(top->val);
                lastPop = top;
                stk.pop();
            }
            else
            {
                if (top->right && top->right != lastPop)
                {
                    stk.push(top->right);
                }
                if (top->left && top->left != lastPop)
                {
                    stk.push(top->left);
                }
            }
        }
        return ans;
    }

    void xianXu(TreeNode *root)
    {
        if (root == nullptr)
            return;
        xianXu(root->right);
        xianXu(root->left);
        cout << root->val << " ";
    }
};
int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.right = &b;
    b.left = &c;
    Solution slu;
    auto vec = slu.postorderTraversal(&a);
    for (auto &a : vec)
    {
        cout << a << " ";
    }
    cout << endl;
    slu.xianXu(&a);
    system("pause");
}
