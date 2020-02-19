//7ReverseInteger
#include <iostream>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        long long res = 0;
        while (x)
        {
            long long tmp = res * 10 + x % 10;
            if (tmp > INT_MAX)
            {
                return 0;
            }
            else
            {
                res = tmp;
            }
            x /= 10;
        }
        return res;
    }
};

int main()
{
    Solution slu;
    cout << INT_MAX << endl;
    cout << slu.reverse(123) << endl;
    cout << slu.reverse(-123) << endl;
    cout << slu.reverse(120) << endl;
    cout << slu.reverse(1534236469) << endl;
    system("pause");
}
