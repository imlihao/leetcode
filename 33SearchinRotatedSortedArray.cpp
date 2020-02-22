//33. Search in Rotated Sorted Array
/**
 *  目标数组相当于两个有序数组连接；
 *  当用Mid分割数组为 a[] b[] 时会出现
 *    1. a,b 都有序
 *    2. a有序b无序
 *    3. b有序a无序
 *  根据以上条件，因为至少确定一边的边界，所以可以判断方向
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size());
    }

    int binarySearch(vector<int> &nums, int t, int low, int high)
    {
        if (low >= high)
            return -1;
        if (low == high - 1)
        {
            return nums[low] == t ? low : -1;
        }
        int mid = (low + high) >> 1;
        if (nums[mid] == t)
            return mid;
        int l1 = low;
        int h1 = mid;
        int l2 = mid + 1;
        int h2 = high;
        bool sp1 = (h1 > l1) && (nums[h1 - 1] < nums[l1]);
        bool sp2 = (h2 > l2) && (nums[h2 - 1] < nums[l2]);
        if (!sp1 && !sp2)
        {
            if (nums[l1] <= t && t <= nums[h1 - 1])
            {
                return binarySearch(nums, t, l1, h1);
            }
            else
            {
                return binarySearch(nums, t, l2, h2);
            }
        }
        else if (sp1)
        {
            if (t >= nums[l2] && t <= nums[h2 - 1])
            {
                return binarySearch(nums, t, l2, h2);
            }
            else
            {
                return binarySearch(nums, t, l1, h1);
            }
        }
        else if (sp2)
        {
            if (t >= nums[l1] && t <= nums[h1 - 1])
            {
                return binarySearch(nums, t, l1, h1);
            }
            else
            {
                return binarySearch(nums, t, l2, h2);
            }
        }
        return -2;
    }
};

int main()
{
    vector<int> vec{4, 5, 6, 7, 0, 1, 2};
    vector<int> vec2{100, 0, 1, 2, 3, 4, 5, 6};
    cout << Solution().search(vec, 6) << endl;
    cout << Solution().search(vec, 0) << endl;
    cout << Solution().search(vec, 2) << endl;
    cout << Solution().search(vec, 4) << endl;
    cout << Solution().search(vec, 9) << endl
         << endl;
    cout << Solution().search(vec2, 100) << endl;
    cout << Solution().search(vec2, 0) << endl;
    cout << Solution().search(vec2, 1) << endl;
    cout << Solution().search(vec2, 6) << endl;
    system("pause");
}