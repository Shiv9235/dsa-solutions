#include <iostream>
#include <vector>

using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int data)
    {
        val = data;
        next = nullptr;
        prev = nullptr;
    }

    ListNode(int data, ListNode *next1, ListNode *back)
    {
        val = data;
        next = next1;
        prev = back;
    }
};

ListNode *convertToDLL(vector<int> nums)
{
    ListNode *head = new ListNode(nums[0]);
    ListNode *temp = head;
    for (int i = 1; i < nums.size(); i++)
    {
        ListNode *mover = new ListNode(nums[i], nullptr, temp);
        temp->next = mover;
        temp = temp->next;
    }

    return head;
}

void printDLL(ListNode *head)
{
    while (head)
    {
        cout << head->val << "    ";
        head = head->next;
    }
}

vector<vector<int>> findPairsWithGivenSum(ListNode *head, int target)
{
    vector<vector<int>> ans;

    if (head == nullptr)
        return ans;

    // Left pointer starts at the head
    ListNode *left = head;

    // Right pointer moves to the tail
    ListNode *right = head;
    while (right->next != nullptr)
    {
        right = right->next;
    }

    // Find unique pairs
    while (left != right && left->val < right->val)
    {
        int sum = left->val + right->val;

        if (sum == target)
        {
            int a = left->val;
            int b = right->val;

            ans.push_back({a, b});

            // Skip duplicate values on the left
            while (left != nullptr && left->val == a)
                left = left->next;

            // Skip duplicate values on the right
            while (right != nullptr && right->val == b)
                right = right->prev;
        }
        else if (sum < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 4, 5, 6, 8, 9};
    int target = 7;

    ListNode *head = convertToDLL(nums);

    vector<vector<int>> ans = findPairsWithGivenSum(head, target);

    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}