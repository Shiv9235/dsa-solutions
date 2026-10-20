#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

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
        left = nullptr;
        right = nullptr;
    }
};

// Convert level-order array into a binary tree
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

// Return -1 if unbalanced; otherwise return the height
int dfsHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lh = dfsHeight(root->left);
    if (lh == -1)
        return -1;

    int rh = dfsHeight(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return max(lh, rh) + 1;
}

bool balancedTree(TreeNode *root)
{
    return dfsHeight(root) != -1;
}

int main()
{
    vector<string> arr = {
        "3", "9", "20", "null", "null", "15", "7"};

    TreeNode *root = convertToTree(arr);

    cout << boolalpha << balancedTree(root) << endl;

    return 0;
}