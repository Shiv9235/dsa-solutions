#include <iostream>
#include <queue>
#include <vector>
#include <string>

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

int findHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lh = findHeight(root->left);
    int rh = findHeight(root->right);

    return max(lh, rh) + 1;
}

int diameterOfBT(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int lh = findHeight(root->left);
    int rh = findHeight(root->right);

    int sum = lh + rh;
    sum = max(sum, lh + rh);

    lh = diameterOfBT(root->left);
    rh = diameterOfBT(root->right);

    return sum;
}

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

int main()
{

    vector<string> arr = {
        "3", "9", "20", "null", "null", "15", "7"};

    TreeNode *root = convertToTree(arr);

    cout << endl;
    cout << diameterOfBT(root);
    cout << endl;

    return 0;
}