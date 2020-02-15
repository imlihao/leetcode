#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0];
        while (low < high)
        {
            int mid = (low + high) / 2;
            int kLess = 0;
            for (int i = 0; i < n; i++)
            {
                int j = i + 1;
                while (j < n && nums[j] - nums[i] <= mid)
                {
                    j++;
                    kLess++;
                }
            }
            if (kLess < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
    int smallestDistancePair2(vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0];
        while (low < high)
        {
            int mid = (low + high) / 2;
            int kLess = 0;
            for (int i = 0; i < n; i++)
            {
                int j = i + 1;
                while (j < n && nums[j] - nums[i] <= mid)
                {
                    j++;
                    kLess++;
                }
            }
            if (kLess < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> vec{1, 6, 1};
    cout << Solution().smallestDistancePair(vec, 3) << endl;
    system("pause");
}
