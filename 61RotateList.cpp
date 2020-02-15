#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * https://leetcode.com/problems/rotate-list/
 * 计算链表长度len,处理不合理情况（len<2||k<1||k%len == 0)
 * 按K分割链表
 * 合并返回新的head
 * */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *tmp = head, *midR, *midL, *ed;
        int len = 0;
        while (tmp != nullptr)
        {
            ++len;
            tmp = tmp->next;
        };
        if (len < 2 || k == 0 || k % len == 0)
        {
            return head;
        };
        k = k % len;
        tmp = head;
        for (int i = 0; i < len - 1; i++)
        {
            if (i == len - k - 1)
            {
                midL = tmp;
                midR = tmp->next;
            }
            tmp = tmp->next;
        }
        tmp->next = head;
        midL->next = nullptr;
        return midR;
    }
};

int main()
{
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    // b.next = &c;
    // c.next = &d;
    d.next = &e;
    Solution slu;
    auto pt = slu.rotateRight(&a, 21);
    while (pt != nullptr)
    {
        cout << pt->val << " ";
        pt = pt->next;
    }
    cout << endl;
    system("pause");
    return 0;
}