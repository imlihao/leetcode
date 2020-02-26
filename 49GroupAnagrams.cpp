//49. Group Anagrams
/**
 * 关键在于两个字符串的比较，认为只要字符串包含的字符相同即相等
 *    方法1:对所有字符进行排序
 *    方法2:对字符进行哈希处理（此处用质数相乘）
 * */
#include <algorithm>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<int> pCode{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
        vector<int> vec(strs.size(), 0);
        vector<long long> tmp;
        vector<vector<string>> res(strs.size(), vector<string>());
        for (int i = 0; i < strs.size(); i++)
        {
            long long hc = 1;
            for (auto &ch : strs[i])
            {
                hc *= pCode[ch - 'a'];
                hc = hc % 100000000000007;
            }
            auto it = find(tmp.begin(), tmp.end(), hc);
            if (it == tmp.end())
            {
                tmp.push_back(hc);
                res[tmp.size() - 1].push_back(strs[i]);
            }
            else
            {
                res[it - tmp.begin()].push_back(strs[i]);
            }
        }
        res.resize(tmp.size());
        return res;
    }
};

int main()
{
    vector<string> vec2;
    for (char a = 'a'; a <= 'z'; ++a)
    {
        vec2.push_back(string(1, a));
    }
    vector<string> vec{"zzzzzzzzzzzzzzzzzz", "zzzzzzzzzzzzzzzzzz","zzzzzzzzzzzzzzzzz"};
    Solution().groupAnagrams(vec);
}