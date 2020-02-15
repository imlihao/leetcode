#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <math.h>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<string> que;
        que.push_back(beginWord);
        vector<bool> flag(wordList.size(), false);
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == beginWord)
            {
                flag[i] = true;
                break;
            }
        }
        vector<vector<string>> ans;
        BFS(beginWord, endWord, wordList, que, flag, ans);
        return ans;
    }

    void BFS(string beginWord, string endWord, vector<string> &wordList, vector<string> &que, vector<bool> &flag, vector<vector<string>> &ans)
    {
        vector<string> layer;
        for (int i = 0; i < que.size(); i++)
        {
            string str = que[i];
            for (int j = 0; j < wordList.size(); j++)
            {
                if (!flag[j] && isLegal(str, wordList[j]))
                {
                    if (endWord == wordList[j])
                    {
                        ans.push_back(vector<string>{str, wordList[j]});
                    }
                    else
                    {
                        flag[j] = true;
                        layer.push_back(wordList[j]);
                    }
                }
            }
        }
        if (layer.size() == 0 || ans.size() > 0)
            return;
        BFS(beginWord, endWord, wordList, layer, flag, ans);
        int n = ans.size();
        if (n > 0)
        {
            for (int i = 0; i < que.size(); i++)
            {
                string str = que[i];
                for (int j = 0; j < n; j++)
                {
                    if (isLegal(str, ans[j][0]))
                    {
                        vector<string> vec{ans[j]};
                        vec.insert(vec.begin(), str);
                        ans.push_back(vec);
                    }
                }
            }
            ans.erase(ans.begin(), ans.begin() + n);
        }
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
        //cout << str1 << " " << str2 << ":" << legal << " " << (legal == 1) << endl;
        return legal == 1;
    }
};

int main()
{
    vector<int> vec{2, 3, 1, 1, 4};
    vector<string> wordList{"a", "b", "c"};
    vector<vector<string>> ans = Solution().findLadders("a", "c", wordList);
    for (vector<string> &a : ans)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    system("pause");
}
