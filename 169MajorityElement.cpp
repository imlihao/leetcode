//169. Majority Element
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, unsigned int> mp;
        for (auto &num : nums)
        {
            if (++mp[num] > (nums.size() / 2))
                return num;
        }
        return -1;
    }
};