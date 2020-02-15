#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m / 2; j++)
            {
                swap(matrix[i][j], matrix[i][m - j - 1]);
            }
        }
        // for (vector<int> &a : matrix)
        // {
        //     for (int &b : a)
        //     {
        //         cout << b << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i + j < m - 1)
                {
                    swap(matrix[i][j], matrix[m - j - 1][m - i - 1]);
                }
            }
        }
        // for (vector<int> &a : matrix)
        // {
        //     for (int &b : a)
        //     {
        //         cout << b << " ";
        //     }
        //     cout << endl;
        // }
    }
};

int main()
{

    //cout << Solution().myPow(0.00001, 2147483647) << endl;
    vector<vector<int>> vec = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    //    swap(vec[0][0], vec[0][1]);
    Solution().rotate(vec);
    // for (vector<int> &a : vec)
    // {
    //     for (int &b : a)
    //     {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    system("pause");
}
