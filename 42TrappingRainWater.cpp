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
    int trap(vector<int> &height)
    {
        int ans = 0, lf = 0, rt = height.size() - 1, maxlf = 0, maxrt = 0;
        while (lf <= rt)
        {
            if (maxlf <= maxrt)
            {
                if (height[lf] > maxlf)
                {
                    maxlf = height[lf];
                }
                else
                {
                    ans += maxlf - height[lf];
                }
                lf++;
            }
            else
            {
                if (height[rt] > maxrt)
                {
                    maxrt = height[rt];
                }
                else
                {
                    ans += maxrt - height[rt];
                }
                rt--;
            }
        }
        return ans;
        // int ans = 0, max = 0;
        // for (int i = 0; i < height.size(); i++)
        // {
        //     max = std::max(max, height[i]);
        // }
        // vector<pair<int, int>> vec(max + 1, std::make_pair(-1, -1));
        // for (int i = 0; i < height.size(); i++)
        // {
        //     if (height[i] == 0)
        //         continue;
        //     if (vec[height[i]].first == -1)
        //     {
        //         vec[height[i]].first = i;
        //         vec[height[i]].second = i;
        //     }
        //     else
        //         vec[height[i]].second = i;
        // }

        // for (int i = vec.size() - 1; i > 0; i--)
        // {
        //     pair<int, int> &pa = vec[i];
        //     if (i < vec.size() - 1)
        //     {
        //         if (pa.first == -1 || (vec[i + 1].first != -1 && pa.first > vec[i + 1].first))
        //             pa.first = vec[i + 1].first;
        //         if (pa.second == -1 || (vec[i + 1].second != -1 && pa.second < vec[i + 1].second))
        //             pa.second = vec[i + 1].second;
        //     }
        //     if (pa.first > -1 && pa.second > -1)
        //     {
        //         for (int j = pa.first + 1; j < pa.second; j++)
        //         {
        //             ans += height[j] < i ? 1 : 0;
        //         }
        //     }
        // }
        // return ans;
    }
};

int main()
{
    vector<int> vt{4, 2, 3};
    auto vec = Solution().trap(vt);
    cout << vec << endl;
    system("pause");
}
