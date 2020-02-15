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
    vector<vector<int>> generateMatrix(int n)
    {
        if (n == 0)
        {
            vector<vector<int>> ans;
            return ans;
        }
        vector<vector<int>> arr = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int curD = 1, curX = 0, curY = n - 1, cN = n;
        int i;
        for (i = 1; i <= n; i++)
        {
            ans[0][i - 1] = i;
        }
        cN--;
        while (cN > 0)
        {
            for (int j = 0; j < cN; j++)
            {
                curX += arr[curD][0];
                curY += arr[curD][1];
                ans[curX][curY] = i++;
            }
            curD = ++curD % arr.size();
            for (int j = 0; j < cN; j++)
            {
                curX += arr[curD][0];
                curY += arr[curD][1];
                ans[curX][curY] = i++;
            }
            curD = ++curD % arr.size();
            cN--;
        }
        return ans;
    }
};

int main()
{
    auto ans = Solution().generateMatrix(0);
    for (auto an : ans)
    {
        for (auto a : an)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << endl;
    system("pause");
}
