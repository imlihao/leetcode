//309. Best Time to Buy and Sell Stock with Cooldown
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int k = (prices.size() + 1) / 3;
        vector<vector<int>> vec(k, vector<int>(prices.size(), 0));
        for (int i = 0; i < k; i++)
        {
            int minV = prices[0];
            for (int j = 1; j < prices.size(); j++)
            {
                if (i == 0)
                {
                    minV = min(minV, prices[j]);
                    vec[i][j] = max(vec[i][j - 1], prices[j] - minV);
                }
                else
                {

                    int idx = j - 3;
                    idx = idx > 0 ? idx : 0;
                    minV = min(minV, prices[j - 1] - vec[i - 1][idx]);
                    vec[i][j] = max(vec[i][j - 1], prices[j] - minV);
                }
            }
        }
        return vec[k - 1][prices.size() - 1];
    }
};

int main()
{
    vector<int> vecs{1, 2};
    vector<int> vec{1, 2, 3, 0, 2};
    vector<int> vec2{1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    vector<int> vec3{3, 3, 5, 0, 0, 3, 1, 4};
    cout << Solution().maxProfit(vecs) << endl;
    cout << Solution().maxProfit(vec) << endl;
    //cout << Solution().maxProfit(vec2) << endl;
    system("pause");
}