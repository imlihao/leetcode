//26. Remove Duplicates from Sorted Array
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 1)
            return 0;
        int i = 0;
        while (i < nums.size() - 1)
        {
            if (nums[i] == nums[i + 1]) //时间复杂度o(n^2)
            {
                nums.erase(nums.begin() + i + 1);
            }
            else
            {
                i++;
            }
        }
        int id = 1;
        for (int i = 1; i < nums.size(); i++)
        {
        }

        return nums.size();
    }

    int removeDuplicates2(vector<int> &nums)
    {
        if (nums.size() < 1)
            return 0;
        int id = 1;
        for (int i = 1; i < nums.size(); i++)//id作为新数组的当前指针  时间复杂度o(n)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[id++] = nums[i];
            }
        }
        return id;
    }
};

int main()
{
    vector<int> vec;
    cout << Solution().removeDuplicates(vec) << endl;
    system("pause");
}