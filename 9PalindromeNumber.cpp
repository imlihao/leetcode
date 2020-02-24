//9. Palindrome Number
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        vector<short> vec;
        while (x > 0)
        {
            vec.push_back(x % 10);
            x /= 10;
        }
        for (int i = 0; i < vec.size(); i++)
        {
            int pa = vec.size() - i - 1;
            if (i < pa)
            {
                if(vec[i]!=vec[pa]){
                    return false;
                }
            }else{
                return true;
            }
        }
        return true;
    }
};

int main(){
    cout << Solution().isPalindrome(1221)<<endl;
    cout << Solution().isPalindrome(1222222)<<endl;
    cout << Solution().isPalindrome(12345678)<<endl;
    cout << Solution().isPalindrome(0)<<endl;
    cout << Solution().isPalindrome(12321)<<endl;
    system("pause");
}