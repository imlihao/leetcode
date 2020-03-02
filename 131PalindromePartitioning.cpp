//131. Palindrome Partitioning
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        if (s.size() < 1)
            return res;
        vector<string> tmp;
        partitionDFS(s, 0, s.size() - 1, res, tmp);
        return res;
    }

    void partitionDFS(string &s, int st, int ed, vector<vector<string>> &res, vector<string> &tmp)
    {
        for (int i = st; i <= ed; i++)
        {
            if (isP(s, st, i))
            {
                tmp.push_back(s.substr(st, i - st+1));
                if (i == ed)
                {
                    res.push_back(tmp);
                }
                else
                {
                    partitionDFS(s, i + 1, ed, res, tmp);
                }
                tmp.pop_back();
            }
        }
    }

    bool isP(string &s, int st, int ed)
    {
        while (st < ed)
        {
            if (s[st] == s[ed])
            {
                st++;
                ed--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    auto a = Solution().partition("aab");
    auto b = Solution().partition("a");
    cout << "end";
    cout << "end";
    cout << "end";
}