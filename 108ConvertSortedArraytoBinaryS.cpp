//108. Convert Sorted Array to Binary Search Tree
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBSTR(nums, 0, nums.size());
    }

    TreeNode *sortedArrayToBSTR(vector<int> &nums, int s, int ed)
    {
        if (s >= ed)
            return nullptr;
        int midPos = (s + ed) / 2;
        TreeNode *node = new TreeNode(nums[midPos]);
        node->left = sortedArrayToBSTR(nums, s, midPos);
        node->right = sortedArrayToBSTR(nums, midPos + 1, ed);
        return node;
    }
};

int main()
{
    vector<int> vec{-10, -3, 0, 5, 9};
    auto root = Solution().sortedArrayToBST(vec);
    system("pause");
}