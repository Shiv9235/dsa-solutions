#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data, ListNode *nextNode)
    {
        val = data;
        next = nextNode;
    }

    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }
};

ListNode *convertToLL(vector<int> nums)
{
    ListNode *head = new ListNode(nums[0]);
    ListNode *mover = head;

    for (int i = 1; i < nums.size(); i++)
    {
        ListNode *temp = new ListNode(nums[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void printLL(ListNode *head)
{
    ListNode *temp = head;

    cout << endl;
    while (temp)
    {
        cout << temp->val << "     ";
        temp = temp->next;
    }
    cout << endl;
}

int sizeOfLL(ListNode *head)
{
    ListNode *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

ListNode *rightRotate(ListNode *head, int k)
{
    int n = sizeOfLL(head);

    if (k == 0 || head == NULL)
    {
        return head;
    }
    if (k % n == 0)
    {
        return head;
    }

    ListNode *temp = head;
    k = k % n;

    int i = 1;
    while (i != n - k)
    {
        temp = temp->next;
        i++;
    }

    ListNode *tempHead = temp->next;
    temp->next = NULL;
    temp = tempHead;

    while (tempHead->next != NULL)
    {
        tempHead = tempHead->next;
    }
    tempHead->next = head;

    head = temp;

    return head;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = convertToLL(nums);
    int k = 2;

    head = rightRotate(head, k);
    printLL(head);

    return 0;
}