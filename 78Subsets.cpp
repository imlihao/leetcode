//78. Subsets
/**
 *  回溯法 
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 1; i <= nums.size(); i++)
        {
            dfs(i, 0, nums, tmp, res);
        }
        res.push_back(tmp);
        return res;
    }

    void dfs(int step, int curPos, vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res)
    {
        --step;
        while (curPos < nums.size())
        {
            tmp.push_back(nums[curPos]);
            if (step == 0)
            {
                res.push_back(tmp);
            }
            else
            {
                dfs(step, curPos + 1, nums, tmp, res);
            }
            tmp.pop_back();
            curPos++;
        }
    }
};

int  main()
{
    vector<int> a{1, 2, 3};
    auto res = Solution().subsets(a);
    a.size();
}