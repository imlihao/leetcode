/**
 * https://leetcode.com/problems/unique-binary-search-trees/
 * 对总结点数为n的有  
 *   f(n 以i（0<=i<=n） 为根节点) = f(i)*f(n - i - 1) 
 * **/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        };
        vector<int> vecwww(n + 10, 0);
        vecwww[0] = 1;
        vecwww[1] = 1;
        vecwww[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            int res = 0;
            for (int j = 0; j < i; j++)
            {
                int left = vecwww[j];
                int right = vecwww[i - j - 1];
                int ans = left * right;
                res = res + ans;
            }
            vecwww[i] = res;
        }
        return vecwww[n];
    }

    int dpRecur(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i;
            int right = n - i - 1;
            int leftNum = dpRecur(left); //可以把值存下来避免重复计算
            int rightNum = dpRecur(right);
            ans += leftNum * rightNum;
        }
        return ans;
    }
};

int main()
{
    Solution slu;
    for (int i = 0; i < 20; i++)
    {
        cout << slu.numTrees(i) << " " << slu.dpRecur(i) << endl;
    }
    system("pause");
}