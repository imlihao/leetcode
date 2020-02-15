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
    int jump(vector<int> &nums)
    {

        if (nums.size() < 2)
            return 0;
        nums[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (nums[i] == 0)
            {
                continue;
            }
            else if (nums[i] + i > nums.size() - 2)
            {
                nums[i] = 1;
            }
            else
            {
                int tmp = nums[i];
                nums[i] = 100000;
                for (int j = tmp; j > 0; j--)
                {
                    if (nums[j + i] != 0)
                    {
                        nums[i] = min(nums[i], nums[i + j]);
                    }
                    if (nums[i] == 1)
                        break;
                }
                nums[i]++;
            }
        }
        return nums[0];
    }

    int jumpBFS(vector<int> &nums)
    {

        if (nums.size() < 2)
            return 0;
        int start = 1, end = nums[0], maxE = 0, size = nums.size(), step = 1;
        cout << nums[0] << endl;
        while (end < size - 1)
        {
            for (int i = start; i < end + 1; i++)
            {
                cout << nums[i] << " ";
                if (nums[i] + i > size - 2)
                {
                    cout << endl;
                    return step + 1;
                }
                maxE = max(maxE, nums[i] + i);
            }
            cout << endl;
            step++;
            start = end + 1;
            end = maxE;
        }
        cout << endl;
        return step;
    }
};

int main()
{
    vector<int> vec{2, 3, 1, 1, 4};
    cout << Solution().jumpBFS(vec) << endl;
    cout << Solution().jump(vec) << endl;
    system("pause");
}
