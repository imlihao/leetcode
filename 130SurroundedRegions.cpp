//130. Surrounded Regions
/**
 *   DFS
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.size() < 3)
        {
            return;
        }
        int szX = board.size();
        int szY = board[0].size();
        vector<vector<bool>> flag(szX, vector<bool>(szY, false));
        vector<int> posArr;
        for (int i = 0; i < szX; i++)
        {
            for (int j = 0; j < szY; j++)
            {
                posArr.clear();
                int isoutside = dfs(board, flag, i, j, posArr);
                if (!isoutside)
                {
                    int pos = 0;
                    while (pos < posArr.size())
                    {
                        board[posArr[pos]][posArr[pos + 1]] = 'X';
                        pos += 2;
                    }
                }
            }
        }
    }

    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &flag, int x, int y, vector<int> &posArr)
    {
        int szX = board.size();
        int szY = board[0].size();
        if (x < 0 || x >= szX || y < 0 || y >= szY)
        {
            return false;
        }
        if (flag[x][y])
            return false;
        flag[x][y] = true;
        bool isBd = false;
        if (x == szX - 1 || x == 0 || y == szY - 1 || y == 0)
        {
            isBd = board[x][y] == 'O';
        }
        if (board[x][y] != 'O')
            return false;
        posArr.push_back(x);
        posArr.push_back(y);
        bool bo1 = dfs(board, flag, x + 1, y, posArr);
        bool bo2 = dfs(board, flag, x - 1, y, posArr);
        bool bo3 = dfs(board, flag, x, y + 1, posArr);
        bool bo4 = dfs(board, flag, x, y - 1, posArr);
        return isBd || bo1 || bo2 || bo3 || bo4;
    }
};

void pt(vector<vector<char>> &vec)
{
    int szX = vec.size();
    int szY = vec[0].size();
    for (int i = 0; i < szX; i++)
    {
        for (int j = 0; j < szY; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<char>> vec{
        {'O', 'O', 'O', 'O', 'X', 'X'},
        {'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'O'},
        {'O', 'X', 'O', 'O', 'O', 'O'}};
    vector<vector<char>> vec2{
        {'X', 'O', 'O', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X'},
        {'O', 'X', 'O', 'X', 'O', 'X'},
        {'O', 'X', 'O', 'O', 'O', 'X'},
        {'O', 'X', 'O', 'X', 'O', 'X'},
        {'O', 'X', 'X', 'O', 'X', 'X'}};
    pt(vec2);
    cout << endl;
    Solution().solve(vec2);
    pt(vec2);
    system("pause");
}
