#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
/**
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 * */
/**
 *  !!!!!!!错误!!!!!!!
 * 有  cnt[i~end] = cnt[i~j] + cnt[j~end] + 1    (当nums[i]>nums[j]) (错误 因为有c[k] (k>j&& c[j]<c[k]<c[i]) )
 * 当nums[j]为向后搜索第一个比nums[i]小的数时
 * 变为 cnt[i~end] = 1+cnt[j~end]
 * 倒序算出cnt[len - i];
 * */

/**
 * 归并排序
 * 在排序中左边的有序序列的下标肯定小于右边的有序序列的下标
 * 当左右融合时左边的
 * 当前需要进行融合的数cnt += 右边以融合的个数；
 *  https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76607/C%2B%2B-O(nlogn)-Time-O(n)-Space-MergeSort-Solution-with-Detail-Explanation  
 * */
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> ans(len, 0);
        vector<int> idxs(len, 0);
        iota(idxs.begin(), idxs.end(), 0);
        this->mergeSort(idxs, ans, nums, 0, len);
        return ans;
    }

    void mergeSort(vector<int> &idxs, vector<int> &res, vector<int> &nums, int st, int ed)
    {
        int len = ed - st;
        if (len > 1)
        {
            int mid = st + len / 2;
            mergeSort(idxs, res, nums, st, mid);
            mergeSort(idxs, res, nums, mid, ed);
            int cnt = 0;
            int idx1 = st;
            int idx2 = mid;
            vector<int> tmp;
            while (idx1 < mid || idx2 < ed)
            {
                if (idx2 >= ed || ((idx1 < mid) && (nums[idxs[idx1]] <= nums[idxs[idx2]])))
                {
                    re//s[idxs[idx1]] += cnt;
                    tmp.push_back(idxs[idx1]);
                    ++idx1;
                }
                else
                {
                    cnt++;
                    tmp.push_back(idxs[idx2]);
                    ++idx2;
                }
            }
            std::move(tmp.begin(), tmp.end(), idxs.begin() + st);
        }
    }
};

int main()
{
    Solution slu;
    vector<int> vec{5, 2, 6, 1};
    auto ans = slu.countSmaller(vec);
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    system("pause");
}