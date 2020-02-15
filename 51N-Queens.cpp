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
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> *ans = new vector<vector<string>>;
        for (int i = 0; i < n; i++)
        {
            vector<pair<int, int>> vec{{0, i}};
            this->nqueen(n, 1, vec, *ans);
        }
        return *ans;
    }
    void nqueen(int n, int layer, vector<pair<int, int>> &pos, vector<vector<string>> &ans)
    {
        if (layer >= n)
        {
            vector<string> vec;
            for (auto &a : pos)
            {
                string str(n, '.');
                str[a.second] = 'Q';
                vec.push_back(str);
            }
            ans.push_back(vec);
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                bool bo = true;
                cout << pos.size() << endl;
                if (pos.size() > layer)
                {
                    pos.erase(pos.begin() + layer, pos.end());
                }
                for (auto &a : pos)
                {
                    if (a.second == i || abs(a.first - layer) == abs(a.second - i))
                    {
                        bo = false;
                    }
                }
                if (bo)
                {
                    pair<int, int> pa(layer, i);
                    pos.push_back(pa);
                    nqueen(n, layer + 1, pos, ans);
                }
            }
        }
        return;
    }
};
int main()
{

    Solution slu;
    auto vec = slu.solveNQueens(5);
    for (auto &a : vec)
    {
        for (auto &b : a)
        {
            cout << b << endl;
        }
        cout << endl;
    }
    cout << endl;
    system("pause");
}
