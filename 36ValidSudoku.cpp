//36. Valid Sudoku
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<bool> flag(10, false);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                flag[j] = false;
            }
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (flag[board[i][j] - 48])
                    {
                        return false;
                    }
                    else
                    {
                        flag[board[i][j] - 48] = true;
                    }
                }
            }
            for (int j = 0; j <= 9; j++)
            {
                flag[j] = false;
            }
            for (int j = 0;  j< 9; j++)
            {
                if (board[j][i] != '.')
                {
                    if (flag[board[j][i] - 48])
                    {
                        return false;
                    }
                    else
                    {
                        flag[board[j][i] - 48] = true;
                    }
                }
            }
        }
        vector<int> posX{0, 0, 0, 3, 3, 3, 6, 6, 6};
        vector<int> posY{0, 3, 6, 0, 3, 6, 0, 3, 6};
        for (int pos = 0; pos < posY.size(); pos++)
        {
            int x = posX[pos];
            int y = posY[pos];
            for (int j = 0; j <= 9; j++)
            {
                flag[j] = false;
            }
            for (int i = x; i < x + 3; i++)
            {
                for (int j = y; j < y + 3; j++)
                {
                    if (board[j][i] != '.')
                    {
                        if (flag[board[j][i] - 48])
                        {
                            return false;
                        }
                        else
                        {
                            flag[board[j][i] - 48] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> vec{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    // vector<char> vec{"5", "3", ".", ".", "7", ".", ".", ".", "."};
    // vector<vector<char>> sudu;
    // for (int i = 0; i < 9; i++)
    // {
    //     sudu.push_back(vec);
    // }
    cout << Solution().isValidSudoku(vec) << endl;
    system("pause");
}