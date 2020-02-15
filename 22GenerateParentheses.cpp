#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    //vector<string> ans;
    vector<string> generateParenthesis(int n)
    {
        // vector<int> vec{1};
        // for (int i = 1; i < n * 2; i++)
        // {
        //     vec.push_back(vec[i - 1] * 2);
        // }
        // bianli(vec, 0, 0, n);
        vector<string> vec;
        DFS(vec, "", n, 0);
        return vec;
    }
    void DFS(vector<string> &vec, string str, int n, int m)
    {
        if (n == 0 && m == 0)
        {
            vec.push_back(str);
        }
        if (n > 0)
        {
            DFS(vec, str + '(', n - 1, m + 1);
        }
        if (m > 0)
        {
            DFS(vec, str + ')', n, m - 1);  
        }
    }
    // void bianli(vector<int> vec, int cur, int pos, int index)
    // {
    //     if (index == 0)
    //     {
    //         if (cur < vec[vec.size() - 1])
    //             return;
    //         string str("");
    //         int pos = 0;
    //         for (int i = vec.size() - 1; i >= 0; i--)
    //         {
    //             char c;
    //             if (cur / vec[i] == 1)
    //             {
    //                 c = '(';
    //                 ++pos;
    //                 cur = cur - vec[i];
    //             }
    //             else
    //             {
    //                 c = ')';
    //                 --pos;
    //             }
    //             str.push_back(c);
    //             if (pos < 0)
    //                 break;
    //             if (i == 0)
    //             {
    //                 ans.push_back(str);
    //             }
    //         }
    //     }
    //     else
    //     {
    //         for (int i = pos; i < vec.size(); i++)
    //         {
    //             bianli(vec, cur + vec[i], i + 1, index - 1);
    //         }
    //     }
    // }
};

int main()
{
    vector<string> vec = Solution().generateParenthesis(3);
    for (string st : vec)
    {
        cout << st << endl;
    }
    system("pause");
}
