#include <iostream>
#include <vector>
#include <map>

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

bool linkedListCycle(Node *head)
{
    map<Node *, int> mpp;
    Node *temp = head;
    while (temp != NULL)
    {
        if (mpp.find(temp) == mpp.end())
        {
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

int main()
{

    return 0;
}