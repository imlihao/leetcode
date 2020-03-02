//125. Valid Palindrome
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            int r = compare(s[i], s[j]);
            if (r == 0)
            {
                i++;
                j--;
            }
            else if (r == 1)
            {
                return false;
            }
            else if (r == 2)
            {
                i++;
            }
            else if (r == 3)
            {
                j--;
            }
        }
        return true;
    }

    int compare(char a, char b)
    {
        if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')))
        {
            return 2;
        }
        if (!((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z') || (b >= '0' && b <= '9')))
        {
            return 3;
        }
        if (a >= 'A' && a <= 'Z')
        {
            a -= ('A' - 'a');
        }
        if (b >= 'A' && b <= 'Z')
        {
            b -= ('A' - 'a');
        }
        if (a == b)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};
int main()
{
    cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << Solution().isPalindrome("race a car") << endl;
    cout << Solution().isPalindrome("aaaaaaaaaaaaaa") << endl;
    cout << Solution().isPalindrome("0p") << endl;
    cout << Solution().isPalindrome("0pppacappp0") << endl;
    system("pause");
}