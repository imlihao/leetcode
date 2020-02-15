/**
 * https://leetcode.com/problems/unique-binary-search-trees-ii/
 * 思路和96UniqueBinarySearchTrees相同
 * */
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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n < 1)
        {
            return vector<TreeNode *>();
        }
        return gTrees(1, n);
    }

    vector<TreeNode *> gTrees(int st, int ed)
    {
        if (st == ed)
        {
            return vector<TreeNode *>{new TreeNode(st)};
        }
        else if (st > ed)
        {
            return vector<TreeNode *>{nullptr};
        }
        else if (st + 1 == ed)
        {
            TreeNode *node1 = new TreeNode(st);
            TreeNode *node2 = new TreeNode(ed);
            TreeNode *node3 = new TreeNode(st);
            TreeNode *node4 = new TreeNode(ed);
            node2->left = node1;
            node3->right = node4;
            return vector<TreeNode *>{node2, node3};
        }
        vector<TreeNode *> vec;
        for (int i = st; i <= ed; ++i)
        {
            auto leftNodes = gTrees(st, i - 1);
            auto rightNodes = gTrees(i + 1, ed);
            for (auto ln : leftNodes)
            {
                for (auto rn : rightNodes)
                {
                    auto nd = new TreeNode(i);
                    nd->left = ln;
                    nd->right = rn;
                    vec.push_back(nd);
                }
            }
        }
        return vec;
    }
};

int main()
{
    auto vec = Solution().generateTrees(3);
    system("pause");
}
