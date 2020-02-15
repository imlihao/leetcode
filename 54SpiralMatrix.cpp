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
/**
 * 
 * 
 * 
 * */
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<vector<int>> arr = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return ans;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> flg(m, vector<bool>(n, false));
        bool go = true;
        int curD = 0, curX = 0, curY = 0;
        while (go)
        {
            vector<int> &dr = arr[curD];
            if (!flg[curX][curY])
            {
                ans.push_back(matrix[curX][curY]);
                flg[curX][curY] = true;
            }
            go = false;
            for (auto ar : arr)
            {
                int nX = curX + ar[0], nY = curY + ar[1];
                if (0 <= nX && nX < m && 0 <= nY && nY < n && !flg[nX][nY])
                {
                    go = true;
                }
            }
            if (go)
            {
                int nX = curX + dr[0], nY = curY + dr[1];
                if (0 <= nX && nX < m && 0 <= nY && nY < n && !flg[nX][nY])
                {
                    curX = nX;
                    curY = nY;
                }
                else
                {
                    curD = ++curD % arr.size();
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> vecs = {{1}, {2}, {3}};
    auto ans = Solution().spiralOrder(vecs);
    for (auto an : ans)
    {
        cout << an << " ";
    }
    cout << endl;
    system("pause");
}
