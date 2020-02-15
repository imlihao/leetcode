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

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
    }
};

int main()
{
    vector<string> a{"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> b{"lo", "eo"};
    auto vec = Solution().wordSubsets(a, b);
    for (auto &a : vec)
    {
        cout << a << endl;
    }
    system("pause");
}
