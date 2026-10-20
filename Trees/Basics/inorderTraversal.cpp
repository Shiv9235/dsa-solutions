#include <iostream>
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
        left = right = NULL;
    }
};

void inorderTraversal(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}

vector<int> inorderTraversalAns(TreeNode *root)
{
    vector<int> ans;
    inorderTraversal(root, ans);

    return ans;
}

void printVector(vector<int> &nums)
{
    cout << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "      ";
    }
    cout << endl;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    root->right->right->left = new TreeNode(9);

    vector<int> ans = inorderTraversalAns(root);

    printVector(ans);

    return 0;
}