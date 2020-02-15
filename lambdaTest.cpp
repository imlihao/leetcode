#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
bool cp(const int cpr, int a)
{
    return cpr == a;
}
int main()
{
    int a[] = {1, 3, 4, 5, 6};
    int sx = 3;
    auto fd = find(begin(a), end(a), sx);
    auto bd = std::bind(cp, std::placeholders::_1, sx);
    auto fd2 = find_if(begin(a), end(a), bd);
    cout << "fd " << *fd << endl
         << "fd2 " << *fd2 << endl;
    system("pause");
}
