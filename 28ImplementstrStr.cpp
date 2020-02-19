//28. Implement strStr()
/**
 * if(!needle)return 0(first postion);
 * */
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int szH = haystack.size();
        int sz = needle.size();
        if (sz == 0)
            return 0;
        if (szH < sz)
            return -1;
        for (int i = 0; i <= szH - sz; i++)
        {
            bool isFind = true;
            for (int j = 0; j < sz; j++)
            {
                if (needle[j] != haystack[i+j]){
                    isFind = false;
                    break;
                }
            }
            if(isFind)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution slu;
    cout << slu.strStr("hello","llo") << endl;
    cout << slu.strStr("hello","ll") << endl;
    cout << slu.strStr("hello","") << endl;
    cout << slu.strStr("hello","zaaaaaaa") << endl;
    system("pause");
}