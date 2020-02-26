//70. Climbing Stairs
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    int climbStairs2(int n)
    {
        vector<int> res{0, 1, 2};
        if (n < 3)
            return res[n];
        res.resize(n + 1);
        for (int i = 3; i <= n; i++)
        {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};

int main()
{
    Solution slu;
    for (int i = 0; i < 30; i++)
    {
        cout << slu.climbStairs(i) << " " << slu.climbStairs2(i) << endl;
    }
    system("pause");
}