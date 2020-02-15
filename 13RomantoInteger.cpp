#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int romanToInt(string s)
    {
        map<char, int> mp{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = mp[*(--s.end())];
        for (auto i = 0; i < s.length() - 1; i++)
        {
            int it = mp.find(s[i])->second;
            int it2 = mp.find(s[i + 1])->second;
            ans = (it < it2) ? (ans - it) : (ans + it);
        }
        return ans;
    }
};
int main()
{
    Solution slu;
    std::cout << slu.romanToInt("MCMXCIV") << std::endl;
    system("pause");
    return 0;
}