//5. Longest Palindromic Substring
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        vector<vector<int>> vec(s.size() + 1, vector<int>(s.size() + 1, 0));
        int maxL = 0;
        string res;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= s.size(); j++)
            {
                int p1 = i - 1;
                int p2 = s.size() - j;
                if (s[p1] == s[p2])
                {
                    vec[i][j] = vec[i - 1][j - 1] + 1;
                    int cur = vec[i][j];
                    if (cur > maxL)
                    {
                        auto tmp = s.substr(i - cur, cur);
                        bool isP = true;
                        for (int k = 0; k < tmp.size(); k++)
                        {
                            int k2 = tmp.size() - k - 1;
                            if (k >= k2)
                            {
                                if (tmp[k] != tmp[k2])
                                {
                                    isP = false;
                                    break;
                                }
                            }
                        }
                        if (isP)
                        {
                            maxL = cur;
                            res = tmp;
                        }
                    }
                }
                else
                {
                    vec[i][j] = 0;
                }
            }
        }
        return res;
    }

    string longestPalindrome2(string s)
    {
        vector<vector<int>> vec(s.size(), vector<int>(s.size(), 0));
        int maxL = 0;
        string res;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (i == j)
                {
                    vec[i][j] = 1;
                }
                else if (i == j - 1)
                {
                    vec[i][j] = s[i] == s[j] ? 2 : 0;
                    if (maxL < vec[i][j])
                    {
                        maxL = vec[i][j];
                        res = s.substr(i, j - i + 1);
                    }
                }
                else if (vec[i + 1][j - 1] > 0 && s[i] == s[j])
                {
                    vec[i][j] = vec[i + 1][j - 1] + 2;
                    if (maxL < vec[i][j])
                    {
                        maxL = vec[i][j];
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    // cout << Solution().longestPalindrome("aaclpncaa") << endl;
    // cout << Solution().longestPalindrome("ssooppabcdcbammm") << endl
    //      << endl;

    cout << Solution().longestPalindrome2("abcdcba") << endl;
    cout << Solution().longestPalindrome2("caabcdcbadddd") << endl;
    cout << Solution().longestPalindrome2("abcdcbapppppppppppppppppppppppppp") << endl;
    cout << Solution().longestPalindrome2("ssooppabcdcbammm") << endl;
    system("pause");
}