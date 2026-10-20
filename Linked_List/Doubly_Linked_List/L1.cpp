#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *back;

    ListNode(int data, ListNode *next1, ListNode *prev)
    {
        val = data;
        next = next1;
        back = prev;
    }

    ListNode(int data)
    {
        val = data;
        next = nullptr;
        back = nullptr;
    }
};

ListNode *convertArrToDLL(vector<int> nums)
{
    ListNode *head = new ListNode(nums[0]);
    ListNode *prev = head;

    for (int i = 1; i < nums.size(); i++)
    {
        ListNode *temp = new ListNode(nums[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void printDLL(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << "    ";
        temp = temp->next;
    }
}

ListNode *deleteHead(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    ListNode *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}

ListNode *deleteTail(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    ListNode *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    ListNode *prev = tail->back;
    tail->back = nullptr;
    prev->next = nullptr;
    delete tail;

    return head;
}

int sizeOfDLL(ListNode *head)
{
    int n = 0;
    while (head)
    {
        n++;
        head = head->next;
    }
    return n;
}

ListNode *deleteKthNode(ListNode *head, int k)
{
    if (head == NULL)
    {
        return nullptr;
    }

    int cnt = 0;
    ListNode *temp = head;

    while (temp)
    {
        cnt++;
        if (cnt == k)
            break;

        temp = temp->next;
    }

    ListNode *front = temp->next;
    ListNode *prev = temp->back;

    if (front == nullptr && prev == nullptr)
    {
        delete temp;
        return nullptr;
    }
    else if (front == nullptr)
    {
        return deleteTail(head);
    }
    else if (prev == nullptr)
    {
        return deleteHead(head);
    }
    else
    {
        front->back = prev;
        prev->next = front;
        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;

        return head;
    }
}

void deleteNode(ListNode *temp)
{
    ListNode *prev = temp->back;
    ListNode *front = temp->next;

    if (front == nullptr)
    {
        prev->next = nullptr;
        temp->back = nullptr;

        delete temp;

        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->next = nullptr;
    delete temp;
}

ListNode *insertBeforeHead(ListNode *head, int val)
{
    ListNode *newHead = new ListNode(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

ListNode *insertBeforeTail(ListNode *head, int val)
{
    if (head->next == nullptr)
    {
        return insertBeforeHead(head, val);
    }
    ListNode *tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    ListNode *prev = tail->back;
    ListNode *temp = new ListNode(val, tail, prev);

    prev->next = temp;
    tail->back = temp;

    return head;
}

ListNode *insertBeforeKthNode(ListNode *head, int val, int k)
{
    int n = sizeOfDLL(head);
    if (k == 1)
        return insertBeforeHead(head, val);
    if (k == n)
        return insertBeforeTail(head, val);

    int cnt = 0;
    ListNode *temp = head;
    while (temp)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    ListNode *prev = temp->back;
    ListNode *newNode = new ListNode(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

void insertBeforeNode(ListNode *node, int val)
{
    ListNode *prev = node->back;

    ListNode *newNode = new ListNode(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = convertArrToDLL(nums);

    cout << endl;
    printDLL(head);
    cout << endl;

    insertBeforeNode(head->next->next, 10);

    // head = insertBeforeHead(head, 10);
    // head = insertBeforeTail(head, 10);

    cout << endl;
    printDLL(head);
    cout << endl;

    return 0;
}