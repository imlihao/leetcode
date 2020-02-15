#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        set<char> all = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'e', '.', '+', '-'};
        set<char> jiaJian = {'+', '-'};
        for (char &a : s)
        {
            if (all.find(a) == all.end())
                return false;
        }
        string::iterator it1 = s.begin();
        string::iterator it2 = s.begin();
        while (it1 != s.end())
        {
            if (*it1 == '+' || *it1 == '-')
            {
                string sub(it2, it1 - 1);
                if (!this->isNOnly(sub))
                {
                    return false; 
                }
                it2 = it1;
            }
            it1++;
        }
        string sub(it2, it1);
        return (this->isNOnly(sub));
    }

    bool isNOnly(string &str)
    {
        cout << "e:" << str << endl;
        if (str.size() == 0)
        {
            return false;
        }
        int ct = 0;
        for (auto &a : str)
        {
            ct += ((a == 'e') ? 1 : 0);
        };
        if (ct == 1)
        {
            int pos = str.find('e');
            string sub1(str.begin(), str.begin() + pos);
            string sub2(str.begin() + pos + 1, str.end());
            if (!isNOnly2(sub1) || !isNOnly2(sub2))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (ct == 0)
        {
            return isNOnly2(str);
        }
        return false;
    }

    bool isNOnly2(string &str)
    {
        cout << "dian:" << str << endl;
        if (str.size() == 0)
        {
            return false;
        }
        int ct = 0;
        for (auto a : str)
        {
            ct += a == '.';
        }
        if (ct > 1)
        {
            return false;
        }
        else if (ct == 1)
        {
            int pos = str.find('.');
            if (pos == 0 || pos == str.size() - 1)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    cout << (Solution().isNumber("1.111e1") ? "true" : "false") << endl;
    system("pause");
}
