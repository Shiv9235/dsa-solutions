#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<vector<int>> ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);

            level.push_back(node->data);
        }

        ans.push_back(level);
    }

    return ans;
}

int main()
{
    return 0;
}