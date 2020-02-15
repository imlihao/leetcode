#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if(nums.size()<3)
            return 0;
        heapSort(nums);
        int mx = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            mx = max(mx, nums[i + 1] - nums[i]);
        }
        return mx;
    }

    void heapSort(vector<int> &nums)
    {
        int sz = nums.size();
        for (int i = sz / 2; i >= 0; i--)
        {
            heapAdjust(nums, i, sz);
        }

        for (int i = 1; i <= sz; i++)
        {
            swap(nums[0], nums[sz - i]);
            heapAdjust(nums, 0, sz - i);
        }
    }

    void heapAdjust(vector<int> &nums, int pos, int len)
    {
        int son = pos * 2 + 1;
        while (son < len)
        {
            if (son + 1 < len && nums[son + 1] > nums[son])
            {
                son++;
            }
            if (nums[pos] < nums[son])
            {
                swap(nums[pos], nums[son]);
                pos = son;
                son = pos * 2 + 1;
            }
            else
            {
                return;
            }
        }
    }
};

int main()
{
    vector<int> vec{3, 6, 9, 1};
    cout << Solution().maximumGap(vec) << endl;
    system("pause");
}