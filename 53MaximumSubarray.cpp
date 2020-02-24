//53. Maximum Subarray
/**
 * 动态规划
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() < 1)
            return 0;
        vector<int> vec(nums.size() + 1, 0);
        int maxS = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int v = nums[i] + vec[i + 1];
            vec[i] = v > nums[i] ? v : nums[i];
            maxS = max(vec[i], maxS);
        }
        return maxS;
    }
};

int main()
{
    vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> vec2{-2};
    vector<int> vec3{31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    cout << Solution().maxSubArray(vec3) << endl;
    cout << Solution().maxSubArray(vec2) << endl;
    cout << Solution().maxSubArray(vec) << endl;
    system("pause");
}