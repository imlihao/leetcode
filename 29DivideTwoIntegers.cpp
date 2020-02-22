//29. Divide Two Integers
/**
 *  可转化为问题 多少个divisor相加可以刚好大于等dividend 时间复杂度o(n)
 *     纯用加法的话，当 divisor=1,dividend = INT_MAX会执行两亿多次操作（2^31-1）
 *     优化方式: dividend >= divisor*2^n1 + divisot*2^n2+...; 优化后时间复杂度应该是o(logn)
 * */
#include <iostream>
using namespace std;
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == 0)
            return 0;
        long long a = std::abs((long long)dividend);
        long long b = std::abs(divisor);
        long long res = 0, cur = 0;
        while (a >= cur + b)
        {
            long long tmp = b, m = 1;
            while (tmp << 1 < a - cur)
            {
                tmp <<= 1;
                m <<= 1;
            }
            cur += tmp;
            res += m;
        }
        bool isMins = dividend < 0;
        bool isMins2 = divisor < 0;
        return (isMins == isMins2) ? res : -res;
    }
};

int main()
{
    cout << Solution().divide(INT_MIN, 1) << endl;
    system("pause");
}