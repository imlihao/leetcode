#include <iostream>
#include <vector>
using namespace std;
int digui(int n)
{
    if (n < 3)
        return 1;
    return digui(n - 1) + digui(n - 2);
}

int feidigui(int n)
{
    if (n < 3)
        return 1;
    int a = 1;
    int b = 1;
    int c = 2;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        int tmp = b;
        b = c;
        a = tmp;
    }
    return c;
}

int main()
{
    // for (int i = 0; i < 20; i++)
    // {
    //     cout << i << " " << digui(i) << " " << feidigui(i) << endl;
    // }
    vector<int> vec{2, 23, 44, 1000222, 99, 1000222, 23, 2, 44};
    int res = 0;
    for (auto v : vec)
    {
        cout << (res ^= v) << endl;
    }
    system("pause");
}

