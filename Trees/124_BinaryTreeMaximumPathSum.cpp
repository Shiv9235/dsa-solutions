#include <iostream>
#include <vector>
#include <string>
#include <queue>

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

TreeNode *convertToTree(vector<string> &arr)
{
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(arr[0]));
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Create left child
        if (i < arr.size() && arr[i] != "null")
        {
            curr->left = new TreeNode(stoi(arr[i]));
            q.push(curr->left);
        }
        i++;

        // Create right child
        if (i < arr.size() && arr[i] != "null")
        {
            curr->right = new TreeNode(stoi(arr[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int maxPath(TreeNode *node, int &ans)
{
    if (node == nullptr)
        return 0;

    int lSum = max(0, maxPath(node->left, ans));
    int rSum = max(0, maxPath(node->right, ans));

    ans = max(ans, (node->val + lSum + rSum));

    return node->val + max(lSum, rSum);
}

int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    maxPath(root, ans);
    return ans;
}

int main()
{
    return 0;
}