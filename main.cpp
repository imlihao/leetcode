#include <iostream>
#include <stack>
#include <string>
#include <vector>
using std::string;
class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        int pLen = 0;
        std::stack<int> stk;
        stk.push(-1);
        if (s.length() == 0)
            return 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')' && stk.top() != -1 && s[stk.top()] == '(')
            {
                stk.pop();
                pLen = pLen < i - stk.top() ? i - stk.top() : pLen;
            }
            else if (s[i] == '(')
                stk.push(i);
            else 
                stk.top() = i;
        }
        return pLen;
        std::vector<int> vec;
        std::cout << "vec size:" << vec.size() << std::endl;
        if (vec.size() == 0)
            return 0;
        if (vec.size() == 1)
            return 2;
        int max = 0;
        std::vector<int> vec2(vec.size());
        vec2[vec.size() - 1] = 1;
        for (auto i = vec.size() - 1; i > 0; i--)
        {
            if (vec[i] - vec[i - 1] == 2)
            {
                vec2[i - 1] = vec2[i] + 1;
            }
            else
            {
                vec2[i - 1] = 1;
            }
            max = max < vec2[i - 1] ? vec2[i - 1] : max;
            //std::cout << max << std::endl;
        }
        return max * 2;
        // std::stack<int> stk;
        // stk.push(-1);
        // int maxL = 0;
        // for (int i = 0; i < s.size(); i++)
        // {
        //     int t = stk.top();
        //     if (t != -1 && s[i] == ')' && s[t] == '(')
        //     {
        //         stk.pop();
        //         maxL = std::max(maxL, i - stk.top());
        //     }
        //     else
        //         stk.push(i);
        // }
        // return maxL;
    }
};

int main()
{
    Solution slu;
    std::cout << slu.longestValidParentheses(")()())") << std::endl;
    system("pause");
}