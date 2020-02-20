//105. Construct Binary Tree from Preorder and Inorder Traversal
#include <iostream>
#include <vector>
#include <algorithm>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() < 1)
            return nullptr;
        int rootValue = preorder[0];
        TreeNode* rt = new TreeNode(rootValue);
        auto it = find(inorder.begin(), inorder.end(), rootValue);
        vector<int> inL(inorder.begin(), it);
        vector<int> inR(it+1,inorder.end());
        auto inLSize = inL.size();
        auto inRSize = inR.size();
        auto pIt = preorder.begin() + 1;
        vector<int> prL(pIt,pIt+inLSize);
        vector<int> prR(pIt+inLSize,pIt+inLSize+inRSize);
        rt->left = buildTree(prL, inL);
        rt->right = buildTree(prR, inR);
        return rt;
    }
};

int main()
{
    vector<int> pr{3,9,20,15,7};
    vector<int> inr{9,3,15,20,7};
    auto node = Solution().buildTree(pr, inr);
    system("pause");
}