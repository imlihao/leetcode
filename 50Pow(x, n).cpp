#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return x;
        }
        else if (n == -1)
        {
            return 1 / x;
        }
        else if (n == 0)
        {
            return 1;
        }
        else if (n == 2)
        {
            return x * x;
        }
        else if (n == -2)
        {
            return 1 / (x * x);
        }
        int yu = n % 2, le = n / 2, le2 = le + yu;
        double ans = myPow(x, le);
        ans *= ans;
        if (yu != 0)
        {
            ans *= ((yu > 0) ? x : 1 / x);
        }
        return ans;
    }
};

int main()
{

    //cout << Solution().myPow(0.00001, 2147483647) << endl;
    cout << Solution().myPow(2, 10) << endl;
    system("pause");
}
