#include <algorithm>
#include <functional>
#include <iostream>
#include <math.h>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() < 2)
            return true;
        //vector<bool> flag(nums.size(), true);
        return greedy(nums, 0);
    }

private:
    //bool greedy(vector<int> &nums, int idx, vector<bool> &flag)
    bool greedy(vector<int> &nums, int idx)
    {
        // if (idx >= nums.size() - 1 || nums[idx] + idx >= nums.size() - 1)
        // {
        //     return true;
        // }
        // else if (nums[idx] == 0)
        // {
        //     return false;
        // }
        // for (int i = nums[idx]; i > 0; i--)
        // {
        //     if (greedy(nums, idx + i))
        //     {
        //         return true;
        //     }
        //     else
        //     {
        //         if (idx + i < nums.size() && nums[idx + i] != 0)
        //         {
        //             nums[idx + i] = 0;
        //         }
        //     }
        // }
        int curMin = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (nums[i] + i >= curMin)
            {
                curMin = i;
            }
            // bool bo = false;
            // // for (int j = nums[i]; j > 0; j--)
            // // {
            // //     if (nums[i + j] != 0)
            // //     {
            // //         bo = true;
            // //         break;
            // //     }
            // // }
            // if (!bo)
            //     nums[i] = 0;
        }
        return curMin == 0;
    }
};

int main()
{
    //cout << Solution().isMatch("b", "*?*?*") << endl;
    vector<int> vec{3, 2, 1, 0, 4};
    cout << Solution().canJump(vec) << endl;
    system("pause");
}
