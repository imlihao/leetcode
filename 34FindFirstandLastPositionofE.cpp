//34. Find First and Last Position of Element in Sorted Array
/**
 *   相对于普通二分搜索条件改变
 *      搜索条件为 nums[i]==t&& i处于边界
 *      执行两次时间复杂度为 o(2logn)
 * 
 *   有更简洁的不用递归方式
 vector<int> searchRange(int A[], int n, int target) {
    int i = 0, j = n - 1;
    vector<int> ret(2, -1);
    // Search for the left one
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;
    
    // Search for the right one
    j = n-1;  // We don't have to set i to 0 the second time.
    while (i < j)
    {
        int mid = (i + j) /2 + 1;	// Make mid biased to the right
        if (A[mid] > target) j = mid - 1;  
        else i = mid;				// So that this won't make the search range stuck.
    }
    ret[1] = j;
    return ret; 
}      
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res{-1, -1};
        if (nums.size() < 1)
            return res;
        res[0] = BinarySearch(nums, 0, nums.size(), target, true);
        res[1] = BinarySearch(nums, 0, nums.size(), target, false);
        return res;
    }

    int BinarySearch(vector<int> &nums, int low, int high, int t, bool findLow)
    {
        if (low >= high)
            return -1;
        int mid = (low + high) / 2;
        if (isTar(nums, mid, t, findLow))
        {
            return mid;
        }
        if (nums[mid] == t)
        {
            if (findLow)
            {
                return BinarySearch(nums, low, mid, t, findLow);
            }
            else
            {
                return BinarySearch(nums, mid + 1, high, t, findLow);
            }
        }
        else
        {
            if (nums[mid] > t)
            {
                return BinarySearch(nums, low, mid, t, findLow);
            }
            else
            {
                return BinarySearch(nums, mid + 1, high, t, findLow);
            }
        }
    }

    bool isTar(vector<int> &nums, int pos, int t, bool findLow)
    {
        return findLow ? isLow(nums, pos, t) : isHigh(nums, pos, t);
    }

    bool isLow(vector<int> &nums, int pos, int t)
    {
        //cout << "find pos:" << pos<<endl;
        if (pos == 0)
        {
            return nums[pos] == t;
        }
        else if (nums[pos] == t && nums[pos - 1] != t)
        {
            return true;
        }
        return false;
    }

    bool isHigh(vector<int> &nums, int pos, int t)
    {
        if (pos == nums.size() - 1)
        {
            return nums[pos] == t;
        }
        else if (nums[pos] == t && nums[pos + 1] != t)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    vector<int> vec{0, 1, 2, 3, 4, 4, 4, 4, 4, 5, 6, 7};
    auto res = Solution().searchRange(vec, 4);
    cout << res[0] << " " << res[1] << endl;
    res = Solution().searchRange(vec, 0);
    cout << res[0] << " " << res[1] << endl;
    res = Solution().searchRange(vec, 9);
    cout << res[0] << " " << res[1] << endl;
    system("pause");
}
