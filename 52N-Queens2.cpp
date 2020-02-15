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
    int totalNQueens(int n)
    {
        //vector<vector<string>> *ans = new vector<vector<string>>;
        int *ans = new int(0);
        vector<pair<int, int>> vec;
        this->nqueen(n, 0, vec, ans);
        return *ans;
    }
    void nqueen(int n, int layer, vector<pair<int, int>> &pos, int *ans)
    {
        if (layer >= n)
        {
            // vector<string> vec;
            // for (auto &a : pos)
            // {
            //     string str(n, '.');
            //     str[a.second] = 'Q';
            //     vec.push_back(str);
            // }
            //ans.push_back(vec);
            (*ans)++;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                bool bo = true;
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
                    pos.pop_back();
                }
            }
        }
        return;
    }
};
int main()
{

    Solution slu;
    cout << slu.totalNQueens(8) << endl;
    system("pause");
}
