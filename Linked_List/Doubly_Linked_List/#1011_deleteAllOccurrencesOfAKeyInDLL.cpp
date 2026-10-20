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

void deleteNode(ListNode *node)
{
    if (node->prev != nullptr)
    {
        node->prev->next = node->next;
    }

    if (node->next != nullptr)
    {
        node->next->prev = node->prev;
    }

    delete node;
}

ListNode *deleteAllOccurrences(ListNode *head, int target)
{
    ListNode *temp = head;

    while (temp != nullptr)
    {
        if (temp->val == target)
        {
            ListNode *nextNode = temp->next;

            if (temp == head)
            {
                head = nextNode;
            }

            deleteNode(temp);
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 1, 2, 4, 1, 3, 1, 1, 1};
    ListNode *head = convertToDLL(nums);

    int target = 1;

    cout << endl;
    printDLL(head);
    cout << endl;

    head = deleteAllOccurrences(head, target);

    printDLL(head);
    cout << endl;

    return 0;
}