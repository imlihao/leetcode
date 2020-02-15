/**
 * https://leetcode.com/problems/search-a-2d-matrix/
 * 二分查找
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int pair2num(pair<int, int> &pr)
    {
        return pr.first * j + pr.second;
    };
    void num2pair(int pos, pair<int, int> &pr)
    {
        int a = pos / j;
        int b = pos % j;
        pr.first = a;
        pr.second = b;
    };
    int i, j, len;
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        this->i = matrix.size();
        if (this->i == 0)
            return false;
        this->j = matrix[0].size();
        this->len = this->i * this->j;
        int st = 0, ed = len - 1;
        pair<int, int> pr;
        while (st <= ed)
        {
            int sum = st + ed;
            int mid = sum / 2;
            this->num2pair(mid, pr);
            if (matrix[pr.first][pr.second] == target)
            {
                return true;
            }
            else if (matrix[pr.first][pr.second] < target)
            {
                st = mid + 1;
            }
            else
            {
                ed = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> vec{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    Solution slu;
    for (int i = 0; i < 52; i++)
    {
        cout << i << ":" << (slu.searchMatrix(vec, i) == true ? "True" : "False") << endl;
    }
    system("pause");
}
