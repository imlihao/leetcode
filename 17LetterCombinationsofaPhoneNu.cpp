//17. Letter Combinations of a Phone Number
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<vector<char>> numVec{
            {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        vector<string> res;
        if (digits.size() < 1)
            return res;
        auto di = stoi(digits);
        vector<string> tmp;
        while (di > 0)
        {
            int cur = di % 10;
            di /= 10;
            auto charVec = numVec[cur - 2];
            for (auto &ch : charVec)
            {
                if (res.size() < 1)
                {
                    tmp.push_back(string(1, ch));
                }
                for (auto &str : res)
                {
                    tmp.push_back(ch + str);
                }
            }
            res = tmp;
            tmp.clear();
        }
        return res;
    }
};
int main()
{
    auto res = Solution().letterCombinations("23");
    for (auto &str : res)
    {
        cout << str << " ";
    }
    system("pause");
}