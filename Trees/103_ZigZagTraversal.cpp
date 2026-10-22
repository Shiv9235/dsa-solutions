#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    deque<TreeNode *> dq;
    dq.push_back(root);

    while (!dq.empty())
    {
        int size = dq.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node;

            if (ans.size() % 2 == 0)
            {
                node = dq.back();
                dq.pop_back();
                if (node->left != NULL)
                    dq.push_front(node->left);
                if (node->right != NULL)
                    dq.push_front(node->right);
            }
            else
            {
                node = dq.front();
                dq.pop_front();
                if (node->right != NULL)
                    dq.push_back(node->right);
                if (node->left != NULL)
                    dq.push_back(node->left);
            }
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
