#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    string intToRoman(int num)
    {
        string str("");
        string roman{"IVXLCDM"};
        int md = 1000, pos = 7;
        if (num > 999)
        {
            str.append(num / md, roman[6]);
            num %= md;
        }
        md = 1000;
        while (md > 1)
        {
            md /= 10;
            pos -= 2;
            int cur = num / md;
            if (cur == 0)
                continue;
            num %= md;
            if (cur > 8) // 9
            {
                str.append(10 - cur, roman[pos - 1]); //C1 D5 M10
                str.append(1, roman[pos+1]);
            }
            else if (cur > 5) //6 7 8
            {
                str.append(1, roman[pos]);
                str.append(cur - 5, roman[pos - 1]); //C1 D5 M10
            }
            else if (cur == 5) //5
            {
                str.append(1, roman[pos]);
            }
            else if (cur > 3) //4
            {
                str.append(5 - cur, roman[pos - 1]);
                str.append(1, roman[pos]);
            }
            else //1 2 3
            {
                str.append(cur, roman[pos - 1]);
            }
        }
        //cout << str << " " << roman << roman[2] << endl;
        return str;
    }
};
int main()
{
    Solution slu;
    std::cout << slu.intToRoman(58) << std::endl;
    system("pause");
    return 0;
}