#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val1, ListNode *next1)
    {
        val = val1;
        next = next1;
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

ListNode *addTwoNumber(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    int n;
    n = l1->val + l2->val;

    ListNode *head = new ListNode(n % 10);
    carry = n / 10;

    ListNode *temp1 = l1->next;
    ListNode *temp2 = l2->next;
    ListNode *temp = head;

    while (temp1 && temp2)
    {

        cout << "yay";

        n = temp1->val + temp2->val + carry;

        temp->next = new ListNode(n % 10);
        temp = temp->next;
        carry = n / 10;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 || temp2)
    {
        if (temp1)
        {
            n = temp1->val + carry;
            temp->next = new ListNode(n % 10);
            temp = temp->next;
            carry = n / 10;

            temp1 = temp1->next;
        }
        else
        {
            n = temp2->val + carry;
            temp->next = new ListNode(n % 10);
            temp = temp->next;
            carry = n / 10;

            temp2 = temp2->next;
        }
    }
    if (carry > 0)
    {
        temp->next = new ListNode(carry);
        temp = temp->next;
    }

    return head;
}

void printLL(ListNode *head)
{
    ListNode *temp = head;
    cout << endl;
    while (temp)
    {
        cout << temp->val;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> list1 = {9, 9, 9, 9, 9, 9, 9};
    vector<int> list2 = {9, 9, 9, 9};

    ListNode *l1 = convertToLL(list1);
    ListNode *l2 = convertToLL(list2);

    ListNode *head = addTwoNumber(l1, l2);

    printLL(l1);
    printLL(l2);
    printLL(head);
    cout << endl;

    return 0;
}