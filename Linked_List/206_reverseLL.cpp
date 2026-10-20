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

Node *reverseLL(Node *head)
{
    Node *newHead = NULL;
    Node *temp = head;

    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    while (temp != NULL)
    {
        Node *up = temp->next;
        temp->next = newHead;
        newHead = temp;
        temp = up;
    }

    return newHead;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 6, 4};
    Node *head = convertArr2LL(arr);

    Node *hi = head;
    Node *temp = reverseLL(head);

    cout << endl;
    while (hi)
    {
        cout << hi->data << "   ";
        hi = hi->next;
    }
    cout << endl;

    cout << endl;
    while (temp)
    {
        cout << temp->data << "   ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}