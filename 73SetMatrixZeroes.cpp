//73. Set Matrix Zeroes
/**
 *  在计算机科学中，一个原地算法（in-place algorithm）基本上不需要额外辅助的数据结构,
 *  然而,允许少量额外的辅助变量来转换数据的算法。
 *  当算法运行时，输入的数据通常会被要输出的部分覆盖掉。
 *  不是原地算法有时候称为非原地（not-in-place）或不得其所（out-of-place）
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int tmppp = -2222222;
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.size() < 1)
            return;
        int row = matrix.size();
        int column = matrix[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    setC(matrix, j, row);
                    setR(matrix, i, column);
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; ++j)
            {
                if (matrix[i][j] == tmppp)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void setC(vector<vector<int>> &matrix, int c, int sz)
    {
        for (int i = 0; i < sz; ++i)
        {
            // if (matrix[i][c] == tmppp)
            //     return;
            if (matrix[i][c] != 0)
            {
                matrix[i][c] = tmppp;
            }
        }
    }

    void setR(vector<vector<int>> &matrix, int r, int sz)
    {
        for (int i = 0; i < sz; ++i)
        {
            // if (matrix[r][i] == tmppp)
            //     return;
            if (matrix[r][i] != 0)
            {
                matrix[r][i] = tmppp;
            }
        }
    }
};