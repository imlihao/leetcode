//139. Word Break
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<int> sizeSt;
        set<string> wrodSt;
        for (auto &wd : wordDict)
        {
            sizeSt.insert(wd.size());
            wrodSt.insert(wd);
        }
        vector<int> vec(s.size() + 1, 0);
        vec[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            for (auto it = sizeSt.begin(); it != sizeSt.end(); it++)
            {
                int st = i - *it + 1;
                if (st > 0)
                {
                    auto str = s.substr(st-1, *it);
                    if (vec[st - 1] == 1 && (wrodSt.find(str) != wrodSt.end()))
                    {
                        vec[i] = 1;
                    }
                }
            }
        }
        return vec[vec.size() - 1] == 1;
    }
};

int main()
{
    string str("leetcode");
    vector<string> vec{"leet", "code"};
    cout << Solution().wordBreak(str, vec) << endl;
    system("pause");
}