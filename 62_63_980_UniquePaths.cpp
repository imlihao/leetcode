/**
 *i ii:动态规划  
 * vec[i][j] =i||j == 0 ?1   :    vec[i-1][j](向下走)+vec[i][j-1](向左走);
 * 
 * iii:深度优先搜索(DPS)加回溯
 * 
 *   搜索到  2 && 搜索步数==可通行个数   返回搜索结果
 *   注意在回溯过程中将更改访问标志
 * */
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> vec(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vec[i][j] = j == 0 ? 1 : (vec[i - 1][j] + vec[i][j - 1]);
            }
        }
        return vec[m - 1][n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> vec(m, vector<long>(n, 1));
        vec[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    if (i == 0 && j == 0)
                    {
                        vec[i][j] = 1;
                    }
                    else if (i == 0)
                    {
                        vec[i][j] = vec[i][j - 1];
                    }
                    else if (j == 0)
                    {
                        vec[i][j] = vec[i - 1][j];
                    }
                    else
                    {
                        vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
                    }
                }
                else
                {
                    vec[i][j] = 0;
                }
            }
        }
        return vec[m - 1][n - 1];
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        int x, y;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
                else if (grid[i][j] == 0)
                {
                    cnt++;
                }
            }
        }
        vector<vector<bool>> flg(m, vector<bool>(n, false));
        int res = up3(grid, cnt, 0, x, y, flg);
        return res;
    }

    int up3(vector<vector<int>> &grid, int cnt, int curCnt, int x, int y, vector<vector<bool>> &flg)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (!(0 <= x && x < m && 0 <= y && y < n))
        {
            return 0;
        }
        if (flg[x][y])
        {
            return 0;
        }
        else
        {
            flg[x][y] = true;
        }
        if (grid[x][y] == 1 || grid[x][y] == 0)
        {
            curCnt += grid[x][y] == 0;
            int a = up3(grid, cnt, curCnt, x + 1, y, flg);
            int b = up3(grid, cnt, curCnt, x - 1, y, flg);
            int c = up3(grid, cnt, curCnt, x, y + 1, flg);
            int d = up3(grid, cnt, curCnt, x, y - 1, flg);
            flg[x][y] = false;
            return a + b + c + d;
        }
        else if (grid[x][y] == 2)
        {
            flg[x][y] = false;
            if (cnt == curCnt)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    vector<vector<int>> grid{{1, -1, -1, -1},
                             {0, -1, -1, -1},
                             {0, 0, 0, 2}};
    vector<vector<int>> grid2{{1, 0},
                              {-1, 2}};
    cout << Solution().uniquePathsIII(grid2) << endl;
    system("pause");
}