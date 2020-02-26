//69. Sqrt(x)

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        int s = 0, l = x;
        if (x < 1)
            return x;
        while (s <= l)
        {
            long long mid = (s + l) / 2;
            long long a = mid * mid;
            long long b = (mid + 1) * (mid + 1);
            if (a == x || (a < x && b > x))
                return mid;
            if (a < x)
            {
                s = mid + 1;
            }
            else
            {
                l = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution slu;
    for (int i = 0; i < 100; i++)
    {
        cout << i << ":" << slu.mySqrt(i) << endl;
    }
    system("pause");
}