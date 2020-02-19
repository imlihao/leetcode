#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /**
     * 选择合并
    * */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
        {
            return nullptr;
        }
        else if (!l1)
        {
            return l2;
        }
        else if (!l2)
        {
            return l1;
        }
        ListNode *head;
        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        ListNode *pos = head;
        while (l1 || l2)
        {
            if (l1 && l2)
            {
                ListNode *cur;
                if (l1->val < l2->val)
                {
                    cur = l1;
                    l1 = l1->next;
                }
                else
                {
                    cur = l2;
                    l2 = l2->next;
                }
                pos->next = cur;
                pos = cur;
            }
            else if (l1)
            {
                pos->next = l1;
                break;
            }
            else if (l2)
            {
                pos->next = l2;
                break;
            }
        }
        return head;
    };
    /**
     * 递归
     * */
    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists2(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists2(l2->next, l1);
            return l2;
        }
    };
};

int main()
{
    ListNode a(1), b(2), c(4), d(1), e(3), f(4);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    auto h = Solution().mergeTwoLists(&a, &d);
    while (h)
    {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
    system("pause");
}