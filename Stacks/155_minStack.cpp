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

class MinStack
{
public:
    ListNode *topNode = nullptr;
    ListNode *minNode = nullptr;
    int sizeStack = 0;

    MinStack()
    {
    }

    void push(int value)
    {

        ListNode *temp = new ListNode(value);
        temp->next = topNode;
        topNode = temp;
        if (minNode == nullptr || value <= minNode->val)
        {
            ListNode *minTemp = new ListNode(value);
            minTemp->next = minNode;
            minNode = minTemp;
        }
        sizeStack += 1;
    }

    void pop()
    {

        if (topNode == nullptr)
        {
            return;
        }

        int value = topNode->val;

        ListNode *temp = topNode;
        topNode = topNode->next;

        delete temp;

        if (value == minNode->val)
        {
            ListNode *minTemp = minNode;
            minNode = minNode->next;
            delete minTemp;
        }
    }

    int top()
    {
        return topNode->val;
    }

    int getMin()
    {
        return minNode->val;
    }
};

int main()
{
}