//122. Best Time to Buy and Sell Stock II
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxP = 0;
        int step = 0;
        int i;
        for ( i= 0; i < prices.size() - 1; i++)
        {
            if (prices[i] <= prices[i + 1])
            {
                ++step;
            }
            else
            {
                if (step > 0)
                {
                    maxP += prices[i] - prices[i - step];
                }
                step = 0;
            }
        }
        if (step != 0)
        {
            maxP += prices[i] - prices[i - step];
        }
        return maxP;
    }
};