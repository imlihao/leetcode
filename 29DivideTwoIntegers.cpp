//29. Divide Two Integers
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