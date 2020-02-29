//79. Word Search
/**
 * DFS + 回溯
 * */
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.size() < 0)
            return 0;
        set<pair<int, int>> closed;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[0] == board[i][j])
                {
                    closed.clear();
                    // string sub = word.substr(0, word.size());
                    if (findStr(board, word, i, j))
                        return true;
                }
            }
        }
        return false;
    }

    bool findStr(vector<vector<char>> &board, string &word, int i, int j)
    {
        int ii = board.size();
        int jj = board[0].size();
        if (i < 0 || i >= ii)
            return false;
        if (j < 0 || j >= jj)
            return false;
        if (board[i][j] == '.')
        {
            return false;
        }
        if (word[0] != board[i][j])
            return false;
        char ch = word[0];
        // auto pr = make_pair(i, j);
        word.erase(word.begin());
        if (word.size() < 1)
            return true;
        //        closed.insert(pr);
        board[i][j] = '.';
        if (findStr(board, word, i + 1, j))
        {
            return true;
        }
        if (findStr(board, word, i - 1, j))
        {
            return true;
        }
        if (findStr(board, word, i, j + 1))
        {
            return true;
        }
        if (findStr(board, word, i, j - 1))
        {
            return true;
        }
        word.insert(word.begin(), ch);
        board[i][j] = ch;
        return false;
    }
};

int main()
{
    vector<vector<char>> b{{'C', 'A', 'A'},
                           {'A', 'A', 'A'},
                           {'B', 'C', 'D'}};
    vector<vector<char>> b2{
        {'a'}
    };

    cout << Solution().exist(b2, "ab");
    system("pause");
}