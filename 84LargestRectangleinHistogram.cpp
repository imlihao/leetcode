//84. Largest Rectangle in Histogram
/**
 *  1.穷举法 o(n^2)(超时)
 *      最大面积肯定是 范围（i~j）* 范围中最小高度min(h[i~j]
 *      穷举范围（计算 范围[i~j]可利用 范围[i~j-1]进行优化 
 *      fanwei[i~j] = min(fanwei[i~j-1]的高度,h[j])*(j-i))
 *  2.穷举法2 o(2*n*)
 *    最大面积[i~j] = 范围内最小高度h[l] * 左右长度
 *    i 肯定等于l左边第一个小于h[i]的位置
 *    j 肯定等于l右边第一个小于h[i]的位置
 *    枚举i,计算以i高的最大面积
 * 
 *    对于计算靠左边最小的位置可利用已经计算的结果；
 *    对于1，2，3，4，5，6这样递增的，计算左边退化为o(n*(n+1)/2) 右边为o(n)
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int sz = heights.size();
        int maxH = 0;
        vector<vector<int>> vec(2, vector<int>(sz, 0));
        for (int i = 0; i < sz; i++)
        {
            for (int j = i; j < sz; j++)
            {
                if (i == 0)
                {
                    vec[1][j] = heights[j];
                }
                else
                {
                    int tmp = vec[0][j - 1];
                    int high = min(tmp / i, heights[j]);
                    vec[1][j] = high * (i + 1);
                }
                maxH = max(vec[1][j], maxH);
            }
            swap(vec[0], vec[1]);
        }
        return maxH;
    }

    int largestRectangleArea2(vector<int> &heights)
    {
        int sz = heights.size();
        vector<int> leftLess(sz, 0);
        vector<int> rightLess(sz, 0);
        for (int i = 0; i < sz; i++)
        {
            int p = i - 1;
            while (p >=0 && heights[p] >= heights[i])
            {
                p = leftLess[p];
            }
            leftLess[i] = p;
        }
        for (int i = sz - 1; i >= 0; i--)
        {
            int p = i + 1;
            while (p < sz && heights[p] >= heights[i])
            {
                p = rightLess[p];
            }
            rightLess[i] = p;
        }
        int maxH = 0;
        for (int i = 0; i < sz;i++){
            maxH = max(maxH, heights[i] * (rightLess[i] - leftLess[i] - 1));
        }
        return maxH;
    }
};

int main()
{
    vector<int> a{2, 1, 5, 6, 2, 3};
    cout << Solution().largestRectangleArea2(a) << endl;
    system("pause");
}