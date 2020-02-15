#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// int sa = wNum - 1, pos = i;
// while (sa > 0)
// {
//     if ((pos += wLen) >= sLen)
//     {
//         break;
//     }
//     if (posVec[pos] == j)
//     {
//         vec
//         break;
//         break;
//     }
//     --sa;
// }
class Solution
{
  public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> posVec(s.size(), -1);
        vector<int> ans;
        if (s.size() == 0 || words.size() == 0)
            return ans;
        int wLen = words[0].size(), sLen = s.size(), wNum = words.size();
        for (int i = sLen - wLen; i >= 0; i--)
        {

            for (int j = 0; j < wNum; j++)
            {
                if (s.compare(i, wLen, words[j]) == 0)
                {
                    int sa = wNum - 1;
                    int jTmp = j;
                    int pos = i;

                    while (sa > 0 && jTmp < wNum)
                    {
                        if ((pos += wLen) >= sLen || posVec[pos] < 0)
                            break;
                        if (posVec[pos] == jTmp)
                        {
                            posVec[pos] = -1;
                            while (jTmp < wNum-1)
                            {
                                jTmp++;
                                if (s.compare(i, wLen, words[jTmp]) == 0)
                                {
                                    posVec[pos] = jTmp;
                                    break;
                                }
                            }
                        }
                        --sa;
                    }
                    posVec[i] = j;
                    break;
                }
            }
            if (posVec[i] > -1)
            {
                int sa = wNum - 1, pos = i;
                if (sa <= 0)
                {
                    ans.push_back(i);
                }
                else
                {
                    while (sa > 0)
                    {
                        if ((pos += wLen) >= sLen || posVec[pos] < 0)
                            break;
                        if (posVec[pos] == posVec[i])
                        {
                            posVec[pos] = -1;
                            break;
                        }
                        if (--sa == 0)
                        {
                            ans.push_back(i);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> vt{"word","good","best","good"};
    auto vec = Solution().findSubstring("wordgoodgoodgoodbestword", vt);
    for (auto st : vec)
    {
        cout << st << endl;
    }
    system("pause");
}
