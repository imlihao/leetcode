//91. Decode Ways
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s == "0")
            return 0;
        if (s.size() < 1)
            return 1;
        if (s.size() < 2)
            return 1;
        if (s.size() < 3)
        {
            if (s == "10")
                return 1;
            if (s[0] == '1')
            {
                return 2;
            }
            if (s[0] == '2' && s[1] <= '6')
            {
                return 2;
            }
            return 1;
        }
        int res = 1;
        if (s[0] == '1' && s[1] == '0')
        {
            res *= numDecodings(s.substr(2, s.size()));
        }
        else
        {
            res *= numDecodings(s.substr(1, s.size()));
            if (s[0] == '1' || (s[0] == '2' && s[1] <= '6'))
            {
                res += numDecodings(s.substr(2, s.size()));
            }
        }
        return res;
    }

    int dp(string s)
    {
        if(s.size()<1)
            return 0;
        vector<int> vec(s.size() + 1, 0);
        vec[0] = 1;
        vec[1] = s[0] == '0' ? 0 : 1;
        char dddd = '0';
        for (int i = 2; i <= s.size(); i++)
        {
            int a = s[i - 1] - 48;
            int b = s[i - 2] - 48;
            b = b * 10 + a;
            if (a > 0 && a < 10)
            {
                vec[i] += vec[i - 1];
            }
            if (b > 9 && b < 27)
            {
                vec[i] += vec[i - 2];
            }
        }
        return vec[s.size()];
    }
};

int main()
{
    Solution slu;
    cout << slu.dp("0")  << endl;
    cout << slu.dp("226")  << endl;
    cout << slu.dp("10")  << endl;
    cout << slu.dp("1023") << endl;
    cout << slu.dp("2221022") << endl;
    cout << slu.dp("12") << endl;
    system("pause");
}