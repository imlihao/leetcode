/**
 * 1从起始位置开始找第一个t[0-x] == t[size-x -- end]
 * 2如果x>mid 
 *     +1 得到答案
 *    或者 +2 消去相等的部分重复1
 *  
 * */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestDecomposition(string text)
    {
        int cnt = 0;
        while (!text.empty())
        {
            int ln = 1;
            int sz = text.size();
            int mid = sz / 2;
            while (ln <= sz)
            {
                int res = compare2(text, 0, ln);
                if (res == 0)
                {
                    ++ln;
                }
                else if (res == 1)
                {
                    cnt += 2;
                    text.erase(text.begin(), text.begin() + ln);
                    text.erase(text.end() - ln, text.end());
                    break;
                }
                else if (res == 2)
                {
                    return ++cnt;
                }
            }
        }
        return cnt;
    }

    int compare2(string &text, int pos, int ln)
    {
        int sz = text.size();
        for (int i = 0; i < ln; i++)
        {
            int f = pos + i;
            int r = sz - ln + i;
            if (r <= f)
                return 2;
            if (text[f] != text[r])
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    cout << Solution().longestDecomposition("ghiabcdefhelloadamhelloabcdefghi") << endl;
    cout << Solution().longestDecomposition("merchant") << endl;
    cout << Solution().longestDecomposition("antaprezatepzapreanta") << endl;
    cout << Solution().longestDecomposition("elvtoelvto") << endl;
    system("pause");
}
