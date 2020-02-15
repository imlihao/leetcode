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
    bool isMatch(string s, string p)
    {
        if (p == "*")
            return true;
        stringstream in(p);
        stringstream out;
        char c, last;
        while (in >> c)
        {
            if (last == '*' && c == '*')
            {
                continue;
            }
            last = c;
            out << (c);
        }
        auto str = out.str();
        if (str == "*")
            return true;
        return cpr(s, str, 0, 0);
    }

private:
    bool cpr(string &s, string &p, int posS, int posP)
    {

        if (posS == s.size() && posP == p.size())
        {
            return true;
        }
        else if (posS >= s.size())
        {
            if (posP < p.size())
            {
                for (int i = posP; i < p.size(); i++)
                {
                    if (p[i] != '*')
                        return false;
                }
            }
            return true;
        }
        else if (posP >= p.size())
        {
            return false;
        }
        if (p[posP] == '*')
        {
            for (int i = posS; i <= s.size(); i++)
            {
                if (cpr(s, p, i, posP + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else if (p[posP] == '?' || p[posP] == s[posS])
        {
            return cpr(s, p, posS + 1, posP + 1);
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    //cout << Solution().isMatch("b", "*?*?*") << endl;
    cout << Solution().isMatch("ba", "*a*") << endl;
    system("pause");
}
