#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/**
 * 堆排序
 * 大根堆：除父节点外对所有的节点i father(i)>i(反之小根堆) 的完全二叉树
 * 
 * 
 * 1.构建大根堆
 *   从深度最大的父节点开始
 *   调整父节点子树为大根堆 
 * 2.取出根节点，填补最后节点
 * 3.调整根节点，重复2直到树为空
 * */
void heapAdjust(vector<int> &vec, int st, int len)
{
    int son = st * 2 + 1;
    while (son < len)
    {
        if (son + 1 < len && vec[son] < vec[son + 1])
        {
            ++son;  
        }
        if (vec[son] < vec[st])
        {
            return;
        }
        else
        {
            std::swap(vec[son], vec[st]);
            st = son;
            son = son * 2 + 1;
        }
    }
}
void headSort(vector<int> &vec)
{
    int len = vec.size();
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        heapAdjust(vec, i, len);
    }
    int i = 1;
    for (; i < len; ++i)
    {
        swap(vec[0], vec[len - i]);
        heapAdjust(vec, 0, len - i);
    }
}

int main()
{
    vector<int> vec{5, 3, 8, 2, 4};
    headSort(vec);
    for (auto n : vec)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    system("pause");
}