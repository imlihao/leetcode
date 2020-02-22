//14. Longest Common Prefix
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() < 1)
            return "";
        auto res = strs[0];
        for (auto &str : strs)
        {
            if (res.size() > str.size())
            {
                res.erase(res.begin() + str.size());
            }
            int i = 0;
            for (; i < res.size();i++){
                if(i>=str.size()||res[i]!=str[i]){
                    break;
                }
            }
            res.erase(res.begin() + i, res.end());
        }
        return res;
    }
};