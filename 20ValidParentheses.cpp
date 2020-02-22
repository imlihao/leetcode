//20. Valid Parentheses
/**
 * 用栈
 * */
#include <iostream>
#include <set>
#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (auto &ch : s)
        {
            if (ch == '{' || ch == '(' || ch == '[')
            {
                stk.push(ch);
            }
            else
            {
                if (stk.empty() 
                || !((stk.top() == '(' && ch == ')') 
                || (stk.top() == '{' && ch == '}')
                || (stk.top() == '[' && ch == ']')) )
                {
                    return false;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};

int main()
{
    Solution slu;
    cout << slu.isValid("{}") << endl;
    cout << slu.isValid("(){}{}[()]") << endl;
    cout << slu.isValid("(){}{(}[()]") << endl;
    cout << slu.isValid("((){}{}[()]") << endl;
    system("pause");
}