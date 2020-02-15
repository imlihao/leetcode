#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {

            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back)
            {
                int sum = nums[front] + nums[back];
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else
                {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);
                    while (front < back && nums[front] == triplet[1])
                        front++;
                    while (front < back && nums[back] == triplet[2])
                        back--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return res;
        // vector<vector<int>> ans;
        // int target = 0;
        // sort(nums, 0, nums.size() - 1);
        // int len = nums.size();

        // for (int i = 0; i < len - 2; i++)
        // {
        //     int lf = i + 1, rt = len - 1, tga = target - nums[i];
        //     while (lf < rt)
        //     {
        //         int sum = nums[lf] + nums[rt];
        //         if (sum < tga)
        //         {
        //             ++lf;
        //         }
        //         else if (sum > tga)
        //         {
        //             --rt;
        //         }
        //         else
        //         {
        //             vector<int> vt{nums[i], nums[lf], nums[rt]};
        //             ans.push_back(vt);
        //             while (lf < rt && nums[lf] == vt[1])
        //                 ++lf;
        //             while (lf < rt && nums[rt] == vt[2])
        //                 --rt;
        //         }
        //     }
        //     while (i < len - 1 && nums[i + 1] == nums[i])
        //         i++;
        // }
        // return ans;
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
    vector vec{0, 0, 0};
    vector ans = slu.threeSum(vec);
    system("pause");
    return 0;
}

// verson 0
//  * // for (int &a : nums)
//         {
//             cout << a << ",";
//         }
//         /**
//          *  枚举 n*log(n)+n^3;
//          * Time Limit Exceeded
//          **/
//         for (int i = 0; i < len; i++)
//         {
//             for (int j = i + 1; j < len; j++)
//             {
//                 for (int k = j + 1; k < len; k++)
//                 {
//                     if (nums[i] + nums[j] + nums[k] == target)
//                     {
//                         bool du = false;
//                         for (vector<int> &t : ans)
//                         {
//                             if (nums[i] == t[0] && nums[j] == t[1])
//                             {
//                                 du = true;
//                                 break;
//                             }
//                         }
//                         if (!du)
//                         {
//                             vector<int> vt{nums[i], nums[j], nums[k]};
//                             ans.push_back(vt);
//                         }
//                     }
//                 }
//             }
//         }
//  *
//  *
//  *
//  *
//  *
//  *
//  * verson 1
//  *  for (int i = 1; i < len - 1; i++)
//         {
//             int lf = i - 1, rt = i + 1;
//             while (lf > -1 && rt < len)
//             {
//                 if (nums[lf] + nums[i] + nums[rt] == target)
//                 {
//                     //     bool du = false;
//                     //     for (vector<int> &t : ans)
//                     //     {
//                     //         if (nums[i] == t[1] && nums[lf] == t[0])
//                     //         {
//                     //             du = true;
//                     //             break;
//                     //         }
//                     //     }
//                     //     if (!du)
//                     //     {
//                     vector<int> vt{nums[lf], nums[i], nums[rt]};
//                     ans.push_back(vt);
//                     // }
//                     while (nums[lf] == vt[0])
//                         lf--;
//                     while (nums[rt] == vt[2])
//                         ++rt;
//                 }
//                 else
//                 {
//                     if (nums[i] + nums[lf] + nums[rt] < target)
//                     {
//                         ++rt;
//                     }
//                     else
//                     {
//                         --lf;
//                     }
//                 }
//             }
//             if (nums[i + 1] == nums[i])
//                 i++;
//         }
//         return ans;
//
