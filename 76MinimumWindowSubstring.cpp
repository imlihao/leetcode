//76. Minimum Window Substring
/**
 * 
 * */
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() < 1)
            return "";
        map<char, int> tmap;
        for (auto &tc : t)
        {
            auto f = tmap.find(tc);
            if (f != tmap.end())
            {
                f->second++;
            }
            else
            {
                tmap.insert(make_pair(tc, 1));
            }
        }
        vector<int> vec;
        vector<char> ss;
        //vector<int> idxs;
        int szT = t.size();
        vector<int> cnt(CHAR_MAX - CHAR_MIN, 0);
        vector<int> cnt2(CHAR_MAX - CHAR_MIN, 0);
        for (int i = 0; i < s.size(); i++)
        {
            auto idx = t.find(s[i]);
            if (idx != string::npos)
            {
                ss.push_back(t[idx]);
                vec.push_back(i);
                cnt2[s[i]]++;
            }
        }
        if (!isContainsAll(cnt2, tmap))
        {
            return "";
        }
        int minL = 0, minR = INT_MAX;
        int L = 0, R = 0;
        cnt[ss[0]]++;
        while (R < ss.size())
        {
            if (!isContainsAll(cnt, tmap))
            {
                if (++R < ss.size())
                {
                    cnt[ss[R]]++;
                }
            }
            else
            {
                int space = vec[R] - vec[L];
                if (space < minR - minL)
                {
                    minR = vec[R];
                    minL = vec[L];
                }
                if (L <= R)
                {
                    cnt[ss[L++]]--;
                }
            }
        }
        return s.substr(minL, minR - minL + 1);
    }

private:
    bool isContainsAll(vector<int> &cnt, map<char, int> &tmap)
    {
        for (auto &mp : tmap)
        {
            if (cnt[mp.first] < mp.second)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution slu;
    cout << slu.minWindow("aa", "aa") << endl;
    cout << slu.minWindow("aaddddd", "aa") << endl;
    cout << slu.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << slu.minWindow("ADOBECOABCBANC", "ABCM") << endl;
    system("pause");
}