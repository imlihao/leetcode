#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<TreeNode *> vec{root};
        vector<vector<int>> res;
        if (!root)
            return res;
        bool bo = false;
        while (!vec.empty())
        {
            int size = vec.size();
            vector<int> a;
            for (int i = 0; i < size; i++)
            {
                if (vec[i]->left)
                    vec.push_back(vec[i]->left);
                if (vec[i]->right)
                    vec.push_back(vec[i]->right);
                a.push_back(vec[i]->val);
            }
            if (bo)
                reverse(a.begin(), a.end());
            ;
            bo = !bo;
            res.push_back(a);
            vec.erase(vec.begin(), vec.begin() + size);
        }
        return res;
    }
};

int main()
{
    TreeNode a(3), b(9), c(20), d(15), e(7);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    auto res = Solution().zigzagLevelOrder(&a);
    system("pause");
}
