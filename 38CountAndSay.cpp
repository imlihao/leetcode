//38. Count and Say
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        auto str = countAndSay(n - 1);
        string res;
        for (int i = 0; i < str.size(); i++)
        {
            int cur = str[i];
            int cnt = 1;
            while (i + 1 < str.size() && str[i] == str[i + 1])
            {
                i++;
                cnt++;
            };
            res.push_back(cnt + 48);
            res.push_back(cur);
        }
        return res;
    }
};

int main()
{
    for (int i = 0; i < 30; i++)
    {
        cout << Solution().countAndSay(i + 1) << endl;
    }
    system("pause");
}