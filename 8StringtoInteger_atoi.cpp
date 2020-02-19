#include <iostream>
#include <set>
#include <string>
using namespace std;
class Solution
{
public:
    int myAtoi(string str)
    {
        //set<char> st{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        short isMins = -1;
        long long res = 0;
        bool isRech = false;
        bool isRechP = false;
        for (auto &ch : str)
        {
            if (ch == ' ' && !isRech)
            {
                continue;
            };
            isRech = true;
            if (ch == '+' || ch == '-')
            {
                if (isMins == -1 && !isRechP)
                {
                    isMins = ch == '-';
                }
                else
                {
                    return isMins > 0 ? -res : res;
                }
            }
            else if (ch >= 48 && ch < 58)
            {
                isRechP = true;
                res = res * 10 + (ch - 48);
                if (res > INT_MAX)
                    return isMins > 0 ? INT_MIN : INT_MAX;
            }
            else
            {
                return isMins > 0 ? -res : res;
            }
        }
        return isMins > 0 ? -res : res;
    }
};

int main()
{
    Solution slu;
    cout << slu.myAtoi("0-1") << endl;
    cout << slu.myAtoi("2147483648") << endl;
    cout << slu.myAtoi("123") << endl;
    cout << slu.myAtoi("   -42") << endl;
    cout << slu.myAtoi("4193 with words") << endl;
    cout << slu.myAtoi("words and 987") << endl;
    cout << slu.myAtoi("-91283472332") << endl;
    cout << slu.myAtoi("42") << endl;
    cout << slu.myAtoi("  -0012a42") << endl;
    cout << slu.myAtoi("   +0 123") << endl;
    system("pause");
}