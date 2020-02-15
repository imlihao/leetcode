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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size() - 3; j++)
        {
            if (nums[j] + nums[j + 1] + nums[j + 2] + nums[j + 3] > target)
                break;
            if (nums[j] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            int curTga = target - nums[j];
            for (int i = j + 1; i < nums.size() - 2; i++)
            {
                if (nums[j] + nums[i] + nums[i + 1] + nums[i + 2] > target)
                    break;
                if (nums[j] + nums[i] + nums[n - 2] + nums[n - 1] < target)
                    continue;
                int tga = curTga - nums[i];
                int front = i + 1;
                int back = nums.size() - 1;
                while (front < back)
                {

                    int sum = nums[front] + nums[back];
                    if (sum < tga)
                        front++;
                    else if (sum > tga)
                        back--;
                    else
                    {
                        vector<int> triplet(4, 0);
                        triplet[0] = nums[j];
                        triplet[1] = nums[i];
                        triplet[2] = nums[front];
                        triplet[3] = nums[back];
                        res.push_back(triplet);
                        while (front < back && nums[front] == triplet[2])
                            front++;
                        while (front < back && nums[back] == triplet[3])
                            back--;
                    }
                }
                while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                    i++;
            }
            while (j + 1 < nums.size() && nums[j + 1] == nums[j])
                j++;
        }
        return res;
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
    vector vec{1, 0, -1, 0, -2, 2};
    vector ans = slu.fourSum(vec, 0);
    system("pause");
    return 0;
}