/**
 * https://leetcode.com/problems/edit-distance
 * 
 * 动态规划
 * 
 * horse 和 ros
 * F[horse,ros] = min
 *     {
 *          F[hors,ro]+(e == s?0:1);（替换）
 *          F[horse,ro]+1   （增加）  
 *          F[hors,ros]+1   （删除）
 *     }
 * */
#include <iostream> 
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        if (word1.size() == 0)
        {
            return word2.size();
        }
        else if (word2.size() == 0)
        {
            return word1.size();
        }
        int len1 = word1.size() + 1, len2 = word2.size() + 1;
        vector<vector<int>> res(len2, vector<int>(len1, 0));
        auto &firstLine = res[0];
        iota(firstLine.begin(), firstLine.end(), 0);
        for (int i = 0; i < len2; i++)
        {
            res[i][0] = i;
        };
        for (int i = 1; i < len2; i++)
        {
            for (int j = 1; j < len1; j++)
            {
                int del = res[i - 1][j] + 1;
                int add = res[i][j - 1] + 1;
                int ins = res[i - 1][j - 1] + ((word2[i - 1] == word1[j - 1]) ? 0 : 1);
                int r = std::min(std::min(del, add), ins);
                res[i][j] = r;
            }
        }
        return res[len2 - 1][len1 - 1];
    }
};
int main()
{
    Solution slu;
    cout << slu.minDistance("intention", "execution") << endl;
    system("pause");
}