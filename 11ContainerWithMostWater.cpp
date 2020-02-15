#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        // int max = 0;
        // for (int i = 0; i < height.size() - 1; i++)
        // {
        //     for (int j = i + 1; j < height.size(); j++)
        //     {
        //         max = std::max(std::abs(i - j) * std::min(height[i], height[j]), max);
        //     }
        // }
        // return max;
        int maxW = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            maxW = max((j - i) * min(height[i], height[j]), maxW);
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return maxW;
    }
};
int main()
{
    Solution slu;
    vector<int> vec{1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << slu.maxArea(vec) << std::endl;
    system("pause");
    return 0;
}