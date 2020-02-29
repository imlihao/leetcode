//121. Best Time to Buy and Sell Stock
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxNum = 0, maxP = 0;
        for (int i = prices.size() - 1; i > -1;--i)
        {
            maxNum = max(maxNum, prices[i]);
            maxP = max(maxP, maxNum - prices[i]);
        }
        return maxP;
    }
};