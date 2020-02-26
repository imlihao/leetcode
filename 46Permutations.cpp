//46. Permutations
using namespace std;
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> st;
        dfs(nums, st, 0, res);
        return res;
    }

    void dfs(vector<int> &nums, vector<int> &st, int cur, vector<vector<int>> &res)
    {
        for (int n : nums)
        {
            if (std::find(st.begin(), st.end(), n) == st.end())
            {
                st.push_back(n);
                cur++;
                if (cur == nums.size())
                {
                    //vector<int> tmp(st.begin(), st.end());
                    res.push_back(st);
                }
                else
                {
                    dfs(nums, st, cur, res);
                }
                st.pop_back();
                cur--;
            }
        }
    }
};

int main()
{
    vector<int> vec{};
    Solution().permute(vec);
}