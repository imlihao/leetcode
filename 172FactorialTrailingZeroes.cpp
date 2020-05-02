//172. Factorial Trailing Zeroes
#include <iostream>
using namespace std;
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        while(n>4){
            n /= 5;
            res += n;
        }
        return res;
    }
};

int main()
{
    Solution().trailingZeroes(1);
    system("pause");
}