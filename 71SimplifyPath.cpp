#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> pArr;
        string tmp;
        for (string::iterator it = path.begin(); it < path.end(); it++)
        {
            char ch = *it;
            if (ch == '/')
            {
                if (tmp.size() > 0)
                {
                    if (tmp[0] == '.' && tmp.size() < 3)
                    {
                        string::size_type sz = tmp.size() - 1 > pArr.size() ? pArr.size() : tmp.size() - 1;
                        pArr.erase(pArr.end() - sz, pArr.end());
                    }
                    else
                    {
                        pArr.push_back(tmp);
                    }
                }
                tmp.clear();
            }
            else if (ch == '.')
            {
                tmp.push_back(ch);
            }
            else
            {
                tmp.push_back(ch);
            }
        }
        if (tmp.size() > 0)
        {
            if (tmp[0] == '.' && tmp.size() < 3)
            {
                string::size_type sz = tmp.size() - 1 > pArr.size() ? pArr.size() : tmp.size() - 1;
                pArr.erase(pArr.end() - sz, pArr.end());
            }
            else
            {
                pArr.push_back(tmp);
            }
        }
        tmp.clear();
        for (string &a : pArr)
        {
            tmp.push_back('/');
            tmp.append(a);
        }
        if (tmp.size() == 0)
            tmp = "/";
        return tmp;
    }
};

int main()
{
    cout << Solution().simplifyPath("/a//b////c/d//././/..") << endl;
    system("pause");
}
