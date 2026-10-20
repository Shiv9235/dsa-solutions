#include <vector>
#include <string>
#include <queue>

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