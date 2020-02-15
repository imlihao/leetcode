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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> vec;
        if (!root)
            return vec;
        vector<TreeNode *> nodeVec{root};
        while (nodeVec.size() > 0)
        {
            vector<int> vt2;
            int len = nodeVec.size();
            for (int i = 0; i < len; i++)
            {
                vt2.push_back(nodeVec[i]->val);
                if (nodeVec[i]->left)
                {
                    nodeVec.push_back(nodeVec[i]->left);
                }
                if (nodeVec[i]->right)
                {
                    nodeVec.push_back(nodeVec[i]->right);
                }
            }
            vec.push_back(vt2);
            nodeVec.erase(nodeVec.begin(), nodeVec.begin() + len);
        }
        return vec;
    }
};
int main()
{
    Solution slu;
    TreeNode a(1), b(2), c(3), d(4);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    vector<vector<int>> veca = slu.levelOrder(&a);
    //std::cout <<  << std::endl;
    system("pause");
    return 0;
}