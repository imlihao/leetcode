#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> vec(3, 0);
        for (int &a : nums)
        {
            vec[a]++;
        }
        for (auto be = nums.begin(); be < nums.begin() + vec[0]; ++be)
        {
            *be = 0;
        }
        for (auto be = nums.begin() + vec[0]; be < nums.begin() + vec[0] + vec[1]; ++be)
        {
            *be = 1;
        }
        for (auto be = nums.begin() + vec[0] + vec[1]; be < nums.begin() + vec[0] + vec[1] + vec[2]; ++be)
        {
            *be = 2;
        }
    }

    void sortColors2(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        for (int i = low; i <= high; i++)
        {
            while(nums[i] == 2 && i < high)
            {
                swap(nums[i], nums[high--]);
            }
            if (nums[i] == 0 && low < i)
            {
                swap(nums[i], nums[low++]);
            }
            
        }
    }
};
int main()
{
    vector<int> nums{1,1,2,2,0,0};
    Solution().sortColors2(nums);
    for (int a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
    system("pause");
}