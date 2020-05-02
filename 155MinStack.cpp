//155. Min Stack
/**
 *  用vector,list,stack都可以
 *  可以用额外的栈存一个不下降序列(put的顺序)，在pop的时候维护
 * 
 * */
#include <forward_list>
#include <iostream>
using namespace std;
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (lst2.empty() || getMin() >= x)
            lst2.push_front(x);
        lst.push_front(x);
    }

    void pop()
    {
        auto tmp = top();
        lst.pop_front();
        if (tmp == getMin())
            lst2.pop_front();
    }

    int top()
    {
        return lst.front();
    }
    int getMin()
    {
        return lst2.front();
    }

private:
    typedef forward_list<int> MLIST;
    MLIST lst;
    MLIST lst2;
    int minElement;
    void updateMin()
    {
        minElement = INT_MAX;
        if (!lst.empty())
        {
            for (auto bg = lst.begin(); bg != lst.end(); bg++)
            {
                minElement = min(minElement, *bg);
            }
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */