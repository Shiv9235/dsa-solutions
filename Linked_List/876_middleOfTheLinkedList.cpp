#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

Node *middleOfLL(Node *head)
{
    Node *temp = head;

    // int cnt = 0;
    // if (head == NULL)
    // {
    //     return head;
    // }

    // while (temp != NULL)
    // {
    //     cnt++;
    //     temp = temp->next;
    // }

    // int middle = (cnt / 2);

    // cnt = 0;

    // temp = head;
    // while (temp != NULL)
    // {

    //     if (cnt == middle)
    //     {
    //         head = temp;
    //         break;
    //     }
    //     temp = temp->next;
    //     cnt++;
    // }

    // return head;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 6, 4};
    Node *head = convertArr2LL(arr);

    cout << endl;
    cout << "Middle of the given Linked List : " << middleOfLL(head)->data << endl;
    cout << endl;

    return 0;
}