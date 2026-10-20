#include <iostream>
#include <vector>

using namespace std;

// DEFINING A SELF DEFINED DATATYPE FOR STORING DATA AS WELL AS ITS LOCATION

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

//          <-----------------       CONVERTING TO THE LINKED LIST AND RETURNING HEAD           ------------------->

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

//            <----------------           LENGTH OF THE LINKED LIST             ------------------->

int lenghtOfLinkedList(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
}

//              <------------------          SEARCHING AN ELEMENT IN A LINKED LIST              --------------->

bool isPresent(Node *head, int val)
{
    Node *temp = head;

    while (temp)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

int main()
{
    //  <-------------   HOW POINTERS WORKS   ----------->

    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};

    // for (int i = 0; i < 10; i++)
    // {
    //     int *head = &arr[i];
    //     cout << head << endl;
    // }

    //  <-------------   USING SELF DEFINED DATA TYPES      ------------->

    // vector<int> arr = {2, 5, 8, 7};
    // Node *y = new Node(arr[0], nullptr);

    // cout << y->data << endl;

    //  <-------------    CREATING A LINKED LIST        ------------------->

    vector<int> arr = {12, 45, 67, 23, 57};
    Node *head = convertArr2LL(arr);

    Node *temp = head;

    cout << endl;
    while (temp)
    {
        cout << temp->data << "   ";
        temp = temp->next;
    }
    cout << endl;

    cout << endl
         << lenghtOfLinkedList(head) << endl;
    cout << endl
         << isPresent(head, 67) << endl;

    return 0;
}