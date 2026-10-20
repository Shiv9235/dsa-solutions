#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int _val)
    {
        val = _val;
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

bool isMirror(TreeNode *l, TreeNode *r)
{
    if (l == nullptr && r == nullptr)
        return true;
    if (l == nullptr || r == nullptr)
        return false;
    if (l->val != r->val)
        return false;

    return isMirror(l->left, r->right) && isMirror(l->right, r->left);
}

bool symmetricTree(TreeNode *root)
{
    if (root == nullptr)
        return true;

    return isMirror(root->left, root->right);
}

int main()
{
    vector<string> arr = {"1", "2", "2", "3", "4", "4", "3"};
    TreeNode *root = convertToTree(arr);

    cout << endl;
    cout << (bool)symmetricTree(root) << endl;
    cout << endl;
    return 0;
}