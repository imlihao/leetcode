//138. Copy List with Random Pointer
// Definition for a Node.
#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        map<Node *, Node *> mp;
        Node *head2 = new Node(head->val);
        head2->random = head->random;
        Node *tmp = head2;
        mp.insert(std::pair<Node *, Node *>(head, head2));
        head = head->next;
        while (head != nullptr)
        {
            Node *nd = new Node(head->val);
            nd->random = head->random;
            tmp->next = nd;
            tmp = nd;
            mp.insert(std::pair<Node *, Node *>(head, nd));
            head = head->next;
        }
        tmp = head2;
        while (tmp)
        {
            if (tmp->random)
            {
                auto it = mp.find(tmp->random);
                tmp->random = it->second;
            }
            tmp = tmp->next;
        }
        return head2;
    }
};

int main()
{
}