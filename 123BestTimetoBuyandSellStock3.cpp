//123. Best Time to Buy and Sell Stock III
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfitDP(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int k = 2;
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
                    minV = min(minV, prices[j-1] - vec[i - 1][j - 1]);
                    vec[i][j] = max(vec[i][j - 1], prices[j] - minV);
                }
            }
        }
        return vec[k - 1][prices.size() - 1];
    }

    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int res = 0, ii = 0, jj = prices.size() - 1;
        auto vecT1 = maxProfitOnceVec2(prices);
        auto vecT2 = maxProfitOnceVec(prices);
        res = vecT1[prices.size() - 1];
        for (int i = 1; i < jj; i++)
        {
            int t1 = vecT1[i];
            int t2 = vecT2[i + 1];
            res = max(res, t1 + t2);
        }
        return res;
    }

    vector<int> maxProfitOnceVec(vector<int> &prices)
    {
        int maxNum = 0, maxP = 0;
        int s = 0, e = prices.size() - 1;
        vector<int> vec(prices.size(), 0);
        for (int i = e; i >= s; --i)
        {
            maxNum = max(maxNum, prices[i]);
            maxP = max(maxP, maxNum - prices[i]);
            vec[i] = maxP;
        }
        return vec;
    }

    vector<int> maxProfitOnceVec2(vector<int> &prices)
    {
        int maxNum = INT_MAX, maxP = 0;
        int s = 0, e = prices.size() - 1;
        vector<int> vec(prices.size(), 0);
        for (int i = s; i <= e; ++i)
        {
            maxNum = min(maxNum, prices[i]);
            maxP = max(maxP, prices[i] - maxNum);
            vec[i] = maxP;
        }
        return vec;
    }

    int maxProfitOnce(vector<int> &prices, int s, int e)
    {
        int maxNum = 0, maxP = 0;
        for (int i = e; i >= s; --i)
        {
            maxNum = max(maxNum, prices[i]);
            maxP = max(maxP, maxNum - prices[i]);
        }
        return maxP;
    }
};

int main()
{
    vector<int> vec{3, 3, 5, 0, 0, 3, 1, 4};
    vector<int> vec2{1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    cout << Solution().maxProfitDP(vec) << endl;
    cout << Solution().maxProfitDP(vec2) << endl;
    system("pause");
}