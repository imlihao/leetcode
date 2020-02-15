#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums, 0, nums.size() - 1);
        int len = nums.size();
        int ans = nums[len - 1] + nums[len - 2] + nums[len - 3];
        for (int i = 0; i < len - 2; i++)
        {
            // if (abs(nums[i] + nums[i + 1] + nums[i + 2] - target) > abs(ans - target))
            // {
            //     break;
            // }
            int lf = i + 1, rt = len - 1;
            while (lf < rt)
            {
                int sum = nums[i] + nums[lf] + nums[rt];
                if (std::abs(sum - target) < std::abs(ans - target))
                {
                    ans = sum;
                }
                if (sum < target)
                {
                    ++lf;
                }
                else if (sum > target)
                {
                    --rt;
                }
                else
                {
                    return target;
                }
            }
            // while (i < len - 2 && nums[i + 1] == nums[i])
            //     i++;
        }
        return ans;
    }
    void sort(vector<int> &nums, int i, int j)
    {
        if (i >= j)
            return;
        int a = i, b = j;
        int tmp = nums[a];
        while (a < b)
        {
            while (a < b && nums[b] >= tmp)
                b--;
            nums[a] = nums[b];
            while (a < b && nums[a] <= tmp)
                a++;
            nums[b] = nums[a];
        }
        nums[a] = tmp;
        sort(nums, i, a - 1);
        sort(nums, a + 1, j);
    }
};
int main()
{
    Solution slu;
    vector vec{0, 2, 1, -3};
    int ans = slu.threeSumClosest(vec, 1);
    cout << ans << endl;
    system("pause");
    return 0;
}