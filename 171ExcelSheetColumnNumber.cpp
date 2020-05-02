//171. Excel Sheet Column Number
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int titleToNumber(string s)
    {
        int res = 0;
        for (auto &ch : s)
        {
            if (res == 0)
            {
                res += ch - 'A' + 1;
            }
            else
            {
                res *= 26 + ch - 'A' + 1;
            }
        }
        return res;
    }
};