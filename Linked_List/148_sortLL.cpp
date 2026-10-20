#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

public:
    ListNode(int val1, ListNode *next1)
    {
        val = val1;
        next = next1;
    }

public:
    ListNode(int val1)
    {
        val = val1;
        next = nullptr;
    }
};

ListNode *convertArr2LL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

ListNode *mergeTwoSortedLL(ListNode *head1, ListNode *head2)
{
    ListNode *temp1 = head1;
    ListNode *temp2 = head2;
    ListNode *dNode = new ListNode(-1);
    ListNode *temp = dNode;

    while (temp1 && temp2)
    {
        if (temp1->val <= temp2->val)
        {
            temp->next = temp1;
            temp = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
    }

    if (temp1)
    {
        temp->next = temp1;
    }
    if (temp2)
    {
        temp->next = temp2;
    }

    return dNode->next;
}

ListNode *midlleNode(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *mid = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        mid = mid->next;
        fast = fast->next->next;
    }
    return mid;
}

ListNode *sortLL(ListNode *head)
{
    // ListNode *temp = head;
    // vector<int> arr;

    // while (temp)
    // {
    //     arr.push_back(temp->val);
    //     temp = temp->next;
    // }
    // sort(arr.begin(), arr.end());

    // temp = head;

    // int i = 0;
    // while (temp && i < arr.size())
    // {
    //     temp->val = arr[i];
    //     temp = temp->next;
    //     i++;
    // }

    //      <------------------             SORTING LINKED LIST USING MERGE SORT             ----------------------->

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *mid = midlleNode(head);
    ListNode *leftHead = head;
    ListNode *rightHead = mid->next;

    mid->next = NULL;

    leftHead = sortLL(leftHead);
    rightHead = sortLL(rightHead);

    return mergeTwoSortedLL(leftHead, rightHead);
}

int main()
{
    vector<int> arr = {-1, 5, 3, 4, 0};

    ListNode *head = convertArr2LL(arr);

    ListNode *temp = sortLL(head);

    cout << endl;
    while (temp)
    {
        cout << temp->val << "     ";

        temp = temp->next;
    }
    cout << endl;

    return 0;
}
