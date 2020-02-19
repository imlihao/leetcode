#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    /**
     * o(n) 过程繁琐
     * */
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> n1(nums1.begin(), nums1.begin() + m);
        int i = 0, j = 0, pos = 0;
        while (i < m || j < n)
        {
            if (i < m && j < n)
            {
                nums1[pos++] = n1[i] < nums2[j] ? n1[i++] : nums2[j++];
            }
            else if (i < m)
            {
                nums1[pos++] = n1[i++];
            }
            else if (j < n)
            {
                nums1[pos++] = nums2[j++];
            }
        }
    }
    /**
     * o(n)  当nums2>nums1时nums[0~m]保持原位;
     *       当nums2<nums1时相当于所有的nums1[0~m]向后迁移
     *       综上位置不会冲突
     * */
    void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, cur = m + n - 1;
        while (j >= 0)
        {
            nums1[cur--] = (i > 0 && nums1[i] >= nums2[j]) ? nums1[i--] : nums2[j--];
        }
    }
};

int main()
{
    vector<int> v1{1, 3, 5, 0, 0, 0};
    vector<int> v2{2, 4, 6};
    Solution().merge2(v1, 3, v2, 3);
    auto it = v1.begin();
    while (it != v1.end())
    {
        cout << *(it++) << " ";
    }
    cout << endl;
    system("pause");
}