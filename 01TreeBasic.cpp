#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){};
};

void printTree(TreeNode *root)
{
    vector<TreeNode *> cache{root};
    vector<string> showStrs;
    stringstream ss;
    bool hasData = true;
    string ept = " ";
    while (hasData)
    {
        hasData = false;
        int sz = cache.size();
        for (int i = 0; i < sz; i++)
        {
            if (cache[i])
            {
                cache.push_back(cache[i]->left);
                cache.push_back(cache[i]->right);
                if (cache[i]->left || cache[i]->right)
                {
                    hasData = true;
                }
                ss << cache[i]->val << ept;
            }
            else
            {
                ss << 'N' << ept;
                cache.push_back(nullptr);
                cache.push_back(nullptr);
            }
        }
        cache.erase(cache.begin(), cache.begin() + sz);
        for (auto &str : showStrs)
        {
            str.insert(str.begin(), ' ');
        }
        showStrs.push_back(ss.str());
        ss.str("");
        ss.clear();
    }
    for (auto &st : showStrs)
    {
        cout << st << endl;
    }
};
void reverseTree(TreeNode *root)
{
    if (!root)
        return;
    auto tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    reverseTree(root->left);
    reverseTree(root->right);
}

/**
 * 验证二叉搜索树 
 * 1.可以进行中序遍历，检查是否有序
 * 2.检查各节点验证min<val<max
 * */
bool vaildBSTree(TreeNode *root, int minNum, int maxNum)
{
    if (!root)
        return true;
    //cout << minNum << " " << maxNum << " " << root->val << endl;
    if (minNum != NULL && root->val < minNum)
    {
        return false;
    }
    if (maxNum != NULL && root->val > maxNum)
    {
        return false;
    }
    bool left = vaildBSTree(root->left, minNum, root->val);
    bool right = vaildBSTree(root->right, root->val, maxNum);
    return left && right;
}
/**
 * Given two binary trees, write a function to check if they are the same or not.
 * */
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    if (p == nullptr || q == nullptr || p->val != q->val)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    TreeNode a(5), b(2), c(8), d(3), e(3), f(9);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    cout << "Tree:" << endl;
    printTree(&a);
    // cout << "reverseTree:" << endl;
    // reverseTree(&a);
    // printTree(&a);
    bool bo = vaildBSTree(&a, NULL, NULL);
    cout << "VaildTree:" << (bo ? "True" : "False") << endl;
    system("pause");
}
