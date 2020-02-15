#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 0)
            return head;
        ListNode *a;
        int len = 0, pos = 0;
        a = head;
        while (a)
        {
            a = a->next;
            len++;
        }
        a = head;
        ListNode *b = nullptr;
        while (a != nullptr)
        {
            if (pos % k == 0 && len - pos >= k)
            {
                auto node = this->rev(a, k);
                if (b)
                {
                    b->next = node;
                }
                else
                {
                    head = node;
                }
                a = node;
            }
            b = a;
            a = a->next;
            pos++;
        }
        return head;
    }

    ListNode *rev(ListNode *head, int k)
    {
        ListNode *a;
        int pos = 1;
        a = head;
        a = head->next;
        ListNode *start = head;
        ListNode *ed = head;
        while (a != nullptr)
        {
            pos++;
            auto next = a->next;
            if (pos <= k)
            {
                a->next = start;
                start = a;
                if (pos == k)
                {
                    ed->next = next;
                }
            }
            a = next;
        }
        return start;
    }
};

int main()
{
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    ListNode *ans = Solution().reverseKGroup(&a, 3);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    system("pause");
}
