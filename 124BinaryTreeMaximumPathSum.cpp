#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    int maxPathSum(TreeNode *root)
    {
        int *max = new int();
        *max = INT_MIN;
        findMax(root, max);
        return *max;
    }
    int findMax(TreeNode *node, int *max)
    {

        if (node == nullptr || node == 0)
            return 0;
        else
        {
            int lf = findMax(node->left, max);
            int rt = findMax(node->right, max);
            //cout << "node:" << node->val << "  lf:" << lf << "  rt:" << rt << endl;
            // lf = std::max(lf, 0);
            // rt = std::max(rt, 0);
            int maxt = std::max(0,std::max(lf, rt)+node->val);
            *max = std::max(rt + lf + node->val, *max);
            return maxt;
        }
    }
};
void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}
int main()
{
    string str{"[9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]"};
    TreeNode *root = stringToTreeNode(str);
    int ret = Solution().maxPathSum(root);
    string out = to_string(ret);
    cout << out << endl;
    system("pause");
}

// int main() {
//     string line;
//     while (getline(cin, line)) {

//     }
//     return 0;
// }