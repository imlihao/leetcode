/**
 * https://leetcode.com/problems/maximal-rectangle/
 * 1.计算每行持续长度
 * 2.逐行计算累计面积，记录最大的
 *       res[pos][width] = 上一行有相同的？+=  :  =;
 * 效率比较低
 * 
 * 正确应该是DP(TODO)
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        int width = matrix[0].size();
        int high = matrix.size();
        vector<vector<pair<int, int>>> hashTable;
        for (int i = 0; i < high; i++)
        {

            auto &vec = matrix[i];
            vector<pair<int, int>> posVec;
            for (int j = 0; j < vec.size(); j++)
            {
                if (vec[j] == '1')
                {
                    posVec.push_back(make_pair(j, 1));
                    int ps = j + 1;
                    int curLen = 2;
                    while (ps < vec.size())
                    {
                        if (vec[ps] == '1')
                        {
                            posVec.push_back(make_pair(j, curLen++));
                            ps++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            hashTable.push_back(posVec);
        }
        vector<vector<int>> res(width, vector<int>(width + 1, 0));
        int resInt = 0;
        for (auto &n : hashTable[0])
        {
            res[n.first][n.second] += n.second;
            resInt = max(res[n.first][n.second], resInt);
        }
        for (int i = 1; i < hashTable.size(); i++)
        {
            auto &tableLast = hashTable[i - 1];
            auto &table = hashTable[i];
            for (auto &n : table)
            {
                bool isConnect = false;
                for (auto &lt : tableLast)
                {
                    if (lt.first == n.first && lt.second == n.second)
                    {
                        isConnect = true;
                        break;
                    }
                }
                if (isConnect)
                {
                    res[n.first][n.second] += n.second;
                    resInt = max(res[n.first][n.second], resInt);
                }
                else
                {
                    res[n.first][n.second] = n.second;
                    resInt = max(res[n.first][n.second], resInt);
                }
            }
        }
        return resInt;
    }
};

int main()
{
    vector<vector<char>> m{{'0', '0', '0', '0', '0'},
                           {'0', '0', '0', '0', '0'},
                           {'0', '0', '0', '0', '0'},
                           {'0', '0', '1', '1', '1'}};
    Solution slu;
    cout << slu.maximalRectangle(m) << endl;
    system("pause");
}