//101. Symmetric Tree
/**
 * 判断左子树和右子树是否对称
 *    左子树左节点 -- 右子树右节点
 *    左子树右节点 -- 右子树左节点
 * */
#include <iostream>
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isSame(root->left, root->right);
    }

    bool isSame(TreeNode *nodeL, TreeNode *nodeR)
    {
        if (!nodeL && !nodeR)
            return true;
        else if (!nodeL || !nodeR)
        {
            return false;
        }
        else if (nodeL->val != nodeR->val)
        {
            return false;
        }
        else
        {
            return isSame(nodeL->left, nodeR->right) && isSame(nodeL->right, nodeR->left);
        }
    }
};