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
 * */
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
    {
        vector<vector<bool>> red(n, vector<bool>(n, false));
        vector<vector<bool>> blue(n, vector<bool>(n, false));
        for (auto r : red_edges)
        {
            red[r[0]][r[1]] = true;
        }
        for (auto r : blue_edges)
        {
            blue[r[0]][r[1]] = true;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ans[i] = 0;
                continue;
            }
            int rS = stStep2(0, i, true, red, blue, n);
            int bS = stStep2(0, i, false, red, blue, n);
            // int rS = stStep(0, i, true, red_edges, blue_edges, n);
            // int bS = stStep(0, i, false, red_edges, blue_edges, n);
            if (rS == -1 && bS == -1)
            {
                ans[i] = -1;
            }
            else
            {
                rS = rS == -1 ? INT_MAX : rS;
                bS = bS == -1 ? INT_MAX : bS;
                ans[i] = rS < bS ? rS : bS;
            }
        }
        return ans;
    }

    int stStep2(int start, int ed, bool isred, vector<vector<bool>> &rm, vector<vector<bool>> &bm, int n)
    {
        vector<bool> flgR(n, false);
        vector<bool> flgB(n, false);
        isred ? flgR[start] = true : flgB[start] = true;
        vector<int> pts{start};
        int cLayer = 1;
        while (pts.size() > 0)
        {
            vector<vector<bool>> &mp = isred ? rm : bm;
            vector<bool> &flg = isred ? flgR : flgB;
            int sz = pts.size();
            for (int i = 0; i < sz; i++)
            {
                int pt = pts[i];
                for (int i = 0; i < n; i++)
                {
                    if (mp[pt][i])
                    {
                        if (i == ed)
                        {
                            return cLayer;
                        }
                        else if (!flg[i])
                        {
                            pts.push_back(i);
                            flg[i] = true;
                        }
                    }
                }
            }
            pts.erase(pts.begin(), pts.begin() + sz);
            isred = !isred;
            ++cLayer;
        }
        return -1;
    }

    int stStep(int start, int ed, bool isred, vector<vector<int>> &rm, vector<vector<int>> &bm, int n)
    {
        vector<bool> flgR(n, false);
        vector<bool> flgB(n, false);
        isred ? flgR[start] = true : flgB[start] = true;
        vector<int> pts{start};
        int cLayer = 1;
        while (pts.size() > 0)
        {
            vector<vector<int>> &mp = isred ? rm : bm;
            vector<bool> &flg = isred ? flgR : flgB;
            int sz = pts.size();
            for (int i = 0; i < sz; i++)
            {
                int pt = pts[i];
                for (auto eg : mp)
                {
                    if (eg[0] == pt)
                    {
                        if (eg[1] == ed)
                        {
                            return cLayer;
                        }
                        else if (!flg[eg[1]])
                        {
                            pts.push_back(eg[1]);
                            flg[eg[1]] = true;
                        } 
                    }
                }
            }
            pts.erase(pts.begin(), pts.begin() + sz);
            isred = !isred;
            ++cLayer;
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> rg{{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    vector<vector<int>> bg{{1, 2}, {2, 3}, {3, 1}};
    auto ans = Solution().shortestAlternatingPaths(5, rg, bg);
    for (auto an : ans)
    {
        cout << an << " ";
    }
    cout << endl;
    system("pause");
}
