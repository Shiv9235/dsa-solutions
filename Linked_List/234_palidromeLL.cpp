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

bool isPalindrome(Node *head)
{
    vector<int> arr;
    Node *temp = head;

    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    if (arr.size() % 2 == 0)
    {
        return false;
    }
    int left = 0, right = arr.size() - 1;

    while (left != right)
    {
        if (arr[left] != arr[right])
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1};
    vector<int> num;

    Node *head = convertArr2LL(arr);

    cout << isPalindrome(head);

    return 0;
}
