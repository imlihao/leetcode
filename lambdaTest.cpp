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


class test
{
public:
    static unsigned int code;
    unsigned int tCode;
    test()
    {
        tCode = code++;
        cout << "create:" << tCode << endl;
    }
    void show()
    {
        cout << "class:" << tCode << endl;
    }
    ~test()
    {
        cout << "destory:" << tCode << endl;
    }
};
unsigned int test::code = 0;

void te(test t)
{
    t.show();
    t.~test();
    test a, b;
    test& c = a;
    a = b;
    cout << "end" << endl;
};

int main()
{
    //test::code = 0;
    test t;
    te(t);
    // int a[] = {1, 3, 4, 5, 6};
    // int sx = 3;
    // auto fd = find(begin(a), end(a), sx);
    // auto bd = std::bind(cp, std::placeholders::_1, sx);
    // auto fd2 = find_if(begin(a), end(a), bd);
    // cout << "fd " << *fd << endl
    //      << "fd2 " << *fd2 << endl;
    system("pause");
}
