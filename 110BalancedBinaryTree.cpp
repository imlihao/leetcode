#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if(root == nullptr){
            return true;
        }
        bool isLeftLeaf = isLeaf(root->left);
        bool isRightLeaf = isLeaf(root->right);
        if (isLeftLeaf && isRightLeaf)
        {
            return true;
        }
        else if (isLeftLeaf || isRightLeaf)
        {
            return false;
        }
        else
        {
            bool next = isBalanced(root->left) && isBalanced(root->right);
            return next;
        }
    }

    bool isLeaf(TreeNode *node)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << s.isBalanced(root) << endl;
}