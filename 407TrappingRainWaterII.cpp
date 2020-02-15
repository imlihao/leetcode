#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        if (heightMap.size() < 3)
        {
            return 0;
        }
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (this->isLowPointF(i, j, heightMap, flag, m, n))
                {
                    vector<pair<int, int>> pa;
                    int minH = min(min(min(heightMap[i - 1][j], heightMap[i + 1][j]), heightMap[i][j + 1]), heightMap[i][j - 1]);
                    ans += minH - heightMap[i][j];
                    heightMap[i][j] = minH;
                    flag[i][j] = true;
                    pa.push_back({i, j});
                    int si = 0;
                    while (si != pa.size())
                    {
                        si = pa.size();
                        for (int k = 0; k < pa.size(); k++)
                        {
                            pair<int, int> a = pa[k];
                            int val = heightMap[a.first][a.second];
                            int im, jn;
                            im = a.first - 1;
                            jn = a.second;
                          
                                pa.push_back({im, jn});
                                flag[im][jn] = true;
                            }
                        }
                        if (si != pa.size())
                        {
                            int minA = INT_MAX;
                            for (auto &a : pa)
                            {
                                if (!flag[a.first - 1][a.second])
                                {
                                    minA = min(minA, heightMap[a.first - 1][a.second]);
                                }
                                if (!flag[a.first + 1][a.second])
                                { 
                                    minA = min(minA, heightMap[a.first + 1][a.second]);
                                }
                                if (!flag[a.first][a.second + 1])
                                {
                                    minA = min(minA, heightMap[a.first][a.second + 1]);
                                }
                                if (!flag[a.first][a.second - 1])
                                {
                                    minA = min(minA, heightMap[a.first][a.second - 1]);
                                }
                            }

                            for (int k = 0; k < pa.size(); k++)
                            {
                                pair<int, int> a = pa[k];
                                if (minA - heightMap[a.first][a.second] == 0)
                                {
                                    si = 0;
                                    break;
                                }
                                ans += minA - heightMap[a.first][a.second];
                                heightMap[a.first][a.second] = minA;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }

    int isLowPoint(int i, int j, vector<vector<int>> &heightMap, vector<vector<bool>> &flag, int m, int n)
    {
        if (i == 0 || i >= m - 1 || j == 0 || j >= n - 1)
            return false;
        int val = heightMap[i][j];
        return (flag[i + 1][j] || val <= heightMap[i + 1][j]) &&
               (flag[i - 1][j] || val <= heightMap[i - 1][j]) &&
               (flag[i][j + 1] || val <= heightMap[i][j + 1]) &&
               (flag[i][j - 1] || val <= heightMap[i][j - 1]);
    }
    int isLowPointF(int i, int j, vector<vector<int>> &heightMap, vector<vector<bool>> &flag, int m, int n)
    {
        if (i == 0 || i >= m - 1 || j == 0 || j >= n - 1)
            return false;
        int val = heightMap[i][j];
        return (val <= heightMap[i + 1][j]) &&
               (val <= heightMap[i - 1][j]) &&
               (val <= heightMap[i][j + 1]) &&
               (val <= heightMap[i][j - 1]);
    }
};
int main()
{

    // vector<vector<int>> vt{{1, 4, 3, 1, 3, 2},
    //                        {3, 2, 1, 3, 2, 4},
    //                        {2, 3, 3, 2, 3, 1}};
    // vector<vector<int>> vt{{12, 13, 1, 12},
    //                        {13, 4, 13, 12},
    //                        {13, 8, 10, 12},
    //                        {12, 13, 12, 12},
    //                        {13, 13, 13, 13}};
    // vector<vector<int>> vt{{5, 5, 5, 1},
    //                        {5, 1, 1, 5},
    //                        {5, 1, 5, 5},
    //                        {5, 2, 5, 8}};
    vector<vector<int>> vt{{5, 8, 7, 7},
                           {5, 2, 1, 5},
                           {7, 1, 7, 1},
                           {8, 9, 6, 9},
                           {9, 8, 9, 9}};
    // vector<vector<int>> vt{{78, 16, 94, 36},
    //                        {87, 93, 50, 22},
    //                        {63, 28, 91, 60},
    //                        {64, 27, 41, 27},
    //                        {73, 37, 12, 69},
    //                        {68, 30, 83, 31},
    //                        {63, 24, 68, 36}};
    auto vec = Solution().trapRainWater(vt);
    cout << vec << endl;
    system("pause");
}

// int trapRainWater(vector<vector<int>> &heightMap)
//     {
//         if (heightMap.size() < 3)
//         {
//             return 0;
//         }
//         int m = heightMap.size(), n = heightMap[0].size();
//         vector<vector<bool>> flag(m, vector<bool>(n, false));
//         int ans = 0;
//         for (int i = 1; i < m - 1; i++)
//         {
//             for (int j = 1; j < n - 1; j++)
//             {
//                 if (flag[i][j])
//                     continue;
//                 flag[i][j] = true;

//                 vector<int> vec;
//                 stack<int> stkI;
//                 stack<int> stkJ;
//                 stkI.push(i);
//                 stkJ.push(j);
//                 set<pair<int, int>> st;
//                 int minH = INT_MAX;
//                 while (!stkI.empty())
//                 {
//                     int curI = stkI.top();
//                     stkI.pop();
//                     int curJ = stkJ.top();
//                     stkJ.pop();
//                     vec.push_back(heightMap[curI][curJ]);
//                     int cV;
//                     //---
//                     curI--;
//                     cV = heightMap[curI][curJ];
//                     if (curI == 0 || curI == m - 1 || curJ == 0 || curJ == n - 1)
//                     {
//                         minH = min(minH, cV);
//                     }
//                     else if (flag[curI][curJ])
//                     {
//                         minH = min(minH, cV);
//                     }
//                     else if (cV >= minH)
//                     {

//                         flag[curI][curJ] = true;
//                     }
//                     else
//                     {
//                         stkI.push(curI);
//                         stkJ.push(curJ);
//                     }
//                     //---
//                     curI += 2;
//                     cV = heightMap[curI][curJ];
//                     if (curI == 0 || curI == m - 1 || curJ == 0 || curJ == n - 1)
//                     {
//                         minH = min(minH, cV);
//                     }
//                     else if (flag[curI][curJ])
//                     {
//                         minH = min(minH, cV);
//                     }
//                     else if (cV >= minH)
//                     {
//                         flag[curI][curJ] = true;
//                     }
//                     else
//                     {
//                         stkI.push(curI);
//                         stkJ.push(curJ);
//                     }
//                     //---
//                     curI--;
//                     curJ--;
//                     cV = heightMap[curI][curJ];
//                     if (curI == 0 || curI == m - 1 || curJ == 0 || curJ == n - 1)
//                     {
//                         minH = min(minH, cV);
//                     }
//                     else if (flag[curI][curJ])
//                     {
//                         minH = min(minH, cV);
//                     }
//                     else if (cV >= minH)
//                     {

//                         flag[curI][curJ] = true;
//                     }
//                     else
//                     {
//                         stkI.push(curI);
//                         stkJ.push(curJ);
//                     }
//                     //---
//                     curJ += 2;
//                     cV = heightMap[curI][curJ];
//                     if (curI == 0 || curI == m - 1 || curJ == 0 || curJ == n - 1)
//                     {
//                         minH = min(minH, cV);
//                     }
//                     else if (flag[curI][curJ])
//                     {
//                         minH = min(minH, cV);
//                     }
//                     else if (cV >= minH)
//                     {

//                         flag[curI][curJ] = true;
//                     }
//                     else
//                     {
//                         stkI.push(curI);
//                         stkJ.push(curJ);
//                     }
//                     heightMap[curI][curJ - 1] = minH;
//                 }
//                 for (int a : vec)
//                 {
//                     if (a < minH)
//                     {
//                         ans += minH - a;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }