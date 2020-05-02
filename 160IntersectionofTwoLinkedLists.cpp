//160. Intersection of Two Linked Lists
/**
 *  方法1:
 *    连接headA的首尾，此时形成了一个有环的链表，用快慢指针确定是否有环
 *    快慢指针相遇的地方距离环入口的距离与头节点距离相等
 *    证明见：https://www.cnblogs.com/yorkyang/p/10876604.html
 *  方法2：
 *    设A,B分别为两链表走到相遇节点的距离，C为相遇节点到尾部的距离；
 *    两节点同时从各头节点出发，每次都走一步，走到尾节点从对方的头节点出发，如果两个链表相交的话，
 *    在相交节点一定会相遇。
 *    1.当A,B相等时，都走A步在相交节点相遇
 *    2.当A,B不等，第一个走A+C+B，第二个走B+C+A在相交节点相遇
 * */
#include <iostream>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == headB)
            return headA;
        if (!headA || !headB)
        {
            return NULL;
        }

        ListNode *a = headA, *b = headB;
        while (a->next)
            a = a->next;
        a->next = headA; //链接headA的首尾
        ListNode *walk = headB, *run = headB;
        while (walk && run && run->next)
        {
            walk = walk->next;
            run = run->next->next;
            if (walk == run)
            {
                ListNode *p1 = headB;
                ListNode *p2 = walk;
                while (p1 != p2)
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                a->next = NULL;
                return p1;
            }
        }
        a->next = NULL;
        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == headB)
            return headA;
        if (!headA || !headB)
        {
            return NULL;
        }
        ListNode *ha = headA, *hb = headB;
        while (ha->next)
            ha = ha->next;
        while (hb->next)
            hb = hb->next;
        if (ha != hb)
            return NULL;
        ha = headA;
        hb = headB;
        while (ha && hb)
        {
            if (ha == hb)
                return ha;
            ha = ha->next;
            hb = hb->next;
            if (!ha)
                ha = headB;
            if (!hb)
                hb = headA;
        }
        return NULL;
    }
};