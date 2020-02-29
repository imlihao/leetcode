//118. Pascal's Triangle

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res(numRows, vector<int>(1, 1));
        int num = 1;
        for (int i = 1; i < numRows; i++)
        {
            for (int j = 1; j < num; j++)
            {
                res[i].push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }
            num++;
            res[i].push_back(1);
        }
        return res;
    }
};

int main(){
    auto a = Solution().generate(6);
    return 0;
}