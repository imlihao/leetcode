#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr)
    {
        cout << "create node:" << this << " " << this->val << endl;
    };
    ~TreeNode()
    {
        cout << "destory node" << this << " " << this->val << endl;
    }
};

class TreeOrder
{
public:
    TreeNode *root;
    TreeOrder()
    {
        auto a = new TreeNode(1);
        auto b = new TreeNode(2);
        auto c = new TreeNode(3);
        auto d = new TreeNode(4);
        auto e = new TreeNode(5);
        auto f = new TreeNode(6);
        auto g = new TreeNode(7);
        a->left = b;
        a->right = c;
        b->left = d;
        d->right = e;
        c->left = f;
        c->right = g;
        root = a;
        cout << "construct::::succ" << endl;
    }
    void printOrder()
    {
        vector<int> vec;
        cout << endl;
        preOrder(root, vec);
        wwww("preOrder", vec);
        preOrder2(root, vec);
        wwww("preOrder", vec);
        inOrder(root, vec);
        wwww("inOrder", vec);
        inOrder2(root, vec);
        wwww("inOrder", vec);
        postOrder(root, vec);
        wwww("postOrder", vec);
        postOrder2(root, vec);
        wwww("postOrder", vec);
        cout << endl;
    }
    void wwww(string str, vector<int> &vec)
    {
        cout << str << ":";
        for (auto &v : vec)
        {
            cout << v << " ";
        }
        if (!vec.empty())
        {
            vec.erase(vec.begin(), vec.end());
        }
        cout << endl;
    }
    void preOrder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    };
    //1.一直向左(进栈并访问)知道该节点没有左节点 2.访问右子树重复1
    void preOrder2(TreeNode *root, vector<int> &res)
    {
        vector<TreeNode *> vec{};
        TreeNode *node = root;
        while (node || !vec.empty())
        {
            while (node)
            {
                res.push_back(node->val);
                vec.push_back(node);
                node = node->left;
            }
            if (!vec.empty())
            {
                node = (*(--vec.end()))->right;
                vec.pop_back();
            }
        }
    };  
    void inOrder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    };
    //1.一直向左(进栈)知道该节点没有左节点 2.出栈(访问节点) 3.访问右子树重复1
    void inOrder2(TreeNode *root, vector<int> &res)
    {
        vector<TreeNode *> vec{};
        TreeNode *node = root;
        while (node || !vec.empty())
        {
            while (node)
            {
                vec.push_back(node);
                node = node->left;
            }
            if (!vec.empty())
            {
                node = (*(--vec.end()));
                res.push_back(node->val);
                node = node->right;
                vec.pop_back();
            }
        }
    };

    void postOrder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }
    //1.一直向左(进栈)知道该节点没有左节点 2.出栈 
    //3.当 节点没有右节点或者右子树已访问 出栈并访问，或者访问右子树重复1
    void postOrder2(TreeNode *root, vector<int> &res)
    {
        vector<TreeNode *> vec{};
        TreeNode *node = root;
        TreeNode *last = nullptr;
        while (node || !vec.empty())
        {
            while (node)
            {
                vec.push_back(node);
                node = node->left;
            }
            if (!vec.empty())
            {
                node = (*(--vec.end()));
                if (node->right && node->right != last)
                {
                    node = node->right;
                }
                else
                {
                    res.push_back(node->val);
                    vec.pop_back();
                    last = node;
                    node = nullptr;
                }
            }
        }
    }
    ~TreeOrder()
    {
        vector<TreeNode *> que{root};
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                if (que[i]->left)
                    que.push_back(que[i]->left);
                if (que[i]->right)
                    que.push_back(que[i]->right);
                delete que[i];
                que[i] = nullptr;
            }
            que.erase(que.begin(), que.begin() + size);
        }
        cout << "destory::::succ" << endl;
    }
};

int main()
{
    TreeOrder().printOrder();
    system("pause");
}