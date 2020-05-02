//146LRUCache
#include <hash_map>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
using namespace std;
using namespace __gnu_cxx;
struct node
{
    int val;
    int key;
    node *next;
    node *pre;
    node(int v, int k) : val(v), key(k), next(nullptr), pre(nullptr) {}
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        list<int> le;
        mymap = new hash_map<int, node *>(capacity);
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key)
    {
        hash_map<int, node *>::iterator it = mymap->find(key);
        if (it == mymap->end())
        {
            return -1;
        }
        else
        {
            auto ndu = it->second;
            updateNode(ndu);
            return ndu->val;
        }
    }

    void put(int key, int value)
    {
        hash_map<int, node *>::iterator it = mymap->find(key);
        if (it == mymap->end()) //未存储时;
        {
            node *nd = new node(value, key);
            mymap->insert(pair<int, node *>(key, nd));
            if (!head)
            {
                head = nd;
                tail = nd;
            }
            else
            {
                nd->next = head;
                head->pre = nd;
                head = nd;
                curC++;
                if (mymap->size() > cap)
                { //容量超了,收缩tail
                    node *tmp = tail;
                    tail = tail->pre;
                    tail->next = nullptr;
                    auto itEd = mymap->find(tmp->key);
                    mymap->erase(itEd);
                    // delete tmp;
                    --curC;
                }
            }
        }
        else
        {
            if (it->second->val != value)
            { //更新内容，并放入表头
                node *ndu = it->second;
                ndu->val = value;
                updateNode(ndu);
            }
        }
    }

private:
    hash_map<int, node *> *mymap;
    int cap;
    int curC = 0;
    node *head;
    node *tail;
    void updateNode(node *ndu)
    {
        if (ndu == head || head == tail) //是表头的话不用更新
        {
            return;
        }
        if (ndu == tail)
        {
            node *tmp = tail;
            tail = tail->pre;
            tail->next = nullptr; //尾部退1
            tmp->next = head;
            head->pre = tmp;
            tmp->pre = nullptr;
            head = tmp;
        }
        else
        {
            //从链表删去ndu
            auto pre = ndu->pre;
            auto next = ndu->next;
            pre->next = next;
            next->pre = pre;
            //加入表头
            ndu->next = head;
            head->pre = ndu;
            head = ndu;
            head->pre = nullptr;
        }
    }
};

class LRUCache2
{
public:
    LRUCache2(int capacity) : cap(capacity)
    {
        mymap = new LII(capacity);
        lst = new LBASE();
    }

    int get(int key)
    {
        auto it = mymap->find(key);
        if (it == mymap->end())
        {
            return -1;
        }
        else
        {
            lst->splice(lst->begin(), *lst, it->second);
            return it->second->second;
        }
    }

    void put(int key, int value)
    {
        auto it = mymap->find(key);
        if (it == mymap->end())
        {
            if (lst->size() == cap)
            {
                int tmpKey = lst->back().first;
                mymap->erase(tmpKey);
                lst->pop_back();
            }
            lst->emplace_front(key, value);
            (*mymap)[key] = lst->begin();
        }
        else
        {
            lst->splice(lst->begin(), *lst, it->second);
            it->second->second = value;
        }
    }

private:
    typedef unordered_map<int, list<pair<int, int>>::iterator> LII;
    typedef list<pair<int, int>> LBASE;
    typedef pair<int, list<int>::iterator> LPAIR;
    LII *mymap;
    LBASE *lst;
    int cap;
};

int main()
{
    LRUCache *obj = new LRUCache(1);
    obj->put(2, 1);
    cout << obj->get(2) << endl;

    // obj->put(1, 11);
    // obj->put(2, 22);
    // cout << obj->get(1) << endl;
    // obj->put(3, 33);
    // cout << obj->get(2) << endl;
    // cout << obj->get(3) << endl;
    // cout << obj->get(1) << endl;
    // obj->put(4, 44);
    // cout << obj->get(3) << endl;
    // cout << obj->get(4) << endl;
    obj->put(5, 55);
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */