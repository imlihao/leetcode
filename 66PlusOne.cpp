//66. Plus One
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
         bool addOne = true;
        int cur = digits.size() - 1;
        while (addOne)
        {
            if (cur == -1)
            {
                digits.insert(digits.begin(), 1);
                addOne = false;
            }
            else
            {
                digits[cur] += 1;
                if (digits[cur] > 9)
                {
                    digits[cur] = 0;
                    addOne = true;
                    cur--;
                }
                else
                {
                    addOne = false;
                }
            }
        }
        return digits;
    }
};