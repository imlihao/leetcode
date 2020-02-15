#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fr = head;
        ListNode *bk = head;
        while (fr != nullptr)
        {
            fr = fr->next;
            if (n-- < 0)
                bk = bk->next;
        }
        if (n == 0)
        {
            fr = head;
            head = head->next;
        }
        else
        {
            fr = bk->next;
            bk->next = bk->next->next;
        }
        delete fr;
        return head;
    }
};
int main()
{
    Solution slu;
    system("pause");
    return 0;
}