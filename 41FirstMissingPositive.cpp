#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        // if (nums.size() == 0)
        //     return 1;
        // if (nums.size() == 1)
        //     return nums[0] == 1 ? 2 : 1;
        // vector<int> vec(nums.size() + 2, 1);
        // // for (int i = 0; i <= nums.size(); i++)
        // // {
        // //     vec.push_back(i);
        // // }
        // for (auto &a : nums)
        // {
        //     if (a > 0 && a <= nums.size()+1)
        //     {
        //         vec[a] = 0;
        //     }
        // }
        // for (int i = 1; i <= nums.size()+1; i++)
        // {
        //     if (vec[i] > 0)
        //         return i;
        // }
        // return 1;
        if(nums.size() == 0) return 1;          //case: nums == null or nums == [], return 1
        for(int i = 0;i < nums.size();i++){                     //use nums array itself, the ideal array should be {1,2,3,4}
            int curr = nums[i];                                 //swap if nums[index] != index + 1;
            while(curr - 1 >= 0 && curr - 1 < nums.size() && curr != nums[curr-1]){
                int next = nums[curr-1];
                nums[curr-1] = curr;
                curr = next;
            }
        }
        for(int i = 0;i< nums.size();i++){                      //check if nums[index] == index + 1;
            if(nums[i] != i+1) return i+1;
        }
        return nums.size()+1;  
    }
};

int main()
{
    vector<int> vt{3,4,-1,1};
    auto vec = Solution().firstMissingPositive(vt);
    cout << vec << endl;
    system("pause");
}
