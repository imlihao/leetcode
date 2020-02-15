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
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<vector<string>> que;
        que.push({beginWord});
        std::set<string> st;
        int ans = 1;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == beginWord)
                ans = 0;
            st.insert(wordList[i]);
        }
        while (!que.empty())
        {
            auto lastSearch = que.front();
            que.pop();
            vector<string> nextSearch;
            for (auto &a : lastSearch)
            {
                for (int i = 0; i < a.size(); i++)
                {
                    auto str = a;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        str[i] = ch;
                        auto it = st.find(str);
                        //cout << "set Find:" << str << ";result:" << (it != st.end()) << endl;
                        if (it != st.end())
                        {
                            if (str == endWord)
                            {
                                return ans + 1;
                            }
                            nextSearch.push_back(str);
                            st.erase(it);
                        }
                    }
                }
            }
            if (!nextSearch.empty())
            {
                que.push(nextSearch);
            }
            ans++;
        }
        return 0;
    }

    int ladderLength2(string beginWord, string endWord, vector<string> &wordList)
    {

        std::set<string> bS{beginWord, "222"}, eS{endWord}, vist, list, tmp;
        int ans = 1;
        for (int i = 0; i < wordList.size(); i++)
        {
            list.insert(wordList[i]);
        }
        if (list.find(endWord) == list.end())
            return 0;
        while (!bS.empty() && !eS.empty())
        {
            if (bS.size() > eS.size())
            {
                tmp = bS;
                bS = eS;
                eS = tmp;
            }
            std::set<string> serch;
            for (auto &a : bS)
            {
                for (int i = 0; i < a.size(); i++)
                {
                    auto str = a;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        str[i] = ch;
                        if (eS.find(str) != eS.end())
                        {
                            return ans + 1;
                        }
                        auto it = list.find(str);
                        if (it != list.end())
                        {
                            serch.insert(str);
                            list.erase(it);
                        }
                    }
                }
            }
            bS = serch;
            ans++;
        }
        return 0;
    }

    bool isLegal(string str1, string str2)
    {
        int legal = 0;
        for (int i = 0; i < str1.size(); i++)
        {
            legal += int(str1[i] != str2[i]);
            if (legal > 1)
                return false;
        }
        return legal == 1;
    }
};

int main()
{
    vector<int> vec{2, 3, 1, 1, 4};
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    cout << Solution().ladderLength("hit", "cog", wordList) << endl;
    cout << Solution().ladderLength2("hit", "cog", wordList) << endl;
    system("pause");
}
