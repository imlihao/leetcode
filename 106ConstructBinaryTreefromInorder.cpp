//106. Construct Binary Tree from Inorder and Postorder Traversal
/**
 * 可理解为  找到根节点和左右子树的中序和后序遍历
 * */
#include <algorithm>
#include <iostream>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() < 1)
            return nullptr;
        int rootValue = postorder[postorder.size() - 1];
        TreeNode *rt = new TreeNode(rootValue);
        auto it = find(inorder.begin(), inorder.end(), rootValue);
        vector<int> inL(inorder.begin(), it);
        vector<int> inR(it + 1, inorder.end());
        auto inLSize = inL.size();
        auto inRSize = inR.size();
        auto pIt = postorder.begin();
        vector<int> prL(pIt, pIt + inLSize);
        vector<int> prR(pIt + inLSize, pIt + inLSize + inRSize);
        rt->left = buildTree(inL, prL);
        rt->right = buildTree(inR, prR);
        return rt;
    }
};

int main()
{
    vector<int> pr{9, 3, 15, 20, 7};
    vector<int> inr{9, 15, 7, 20, 3};
    auto node = Solution().buildTree(pr, inr);
    system("pause");
}