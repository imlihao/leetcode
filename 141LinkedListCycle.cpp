//141. Linked List Cycle
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *tmp = new ListNode(-1);
        ListNode *node;
        while (head != nullptr)
        {
            if (head->next == head || head->next == tmp)
                return 1;
            node = head;
            head = head->next;
            node->next = tmp;
        }
        delete tmp;
        return false;
    }
};