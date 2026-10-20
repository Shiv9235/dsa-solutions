#include <iostream>

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

//      <-------------------            QUEUE IMPLEMENTATION USING LINKED LIST.             ------------------>

class QueueImplUsingLL
{
    Node *start = nullptr;
    Node *end = nullptr;

    int sizeQueue = 0;

    void pushElQ(int x)
    {
        Node *temp = new Node(x);
        if (start == nullptr)
        {
            start = temp;
            end = temp;
            cout << "First Element is pushed......" << endl;
        }
        else
        {
            end = temp;
            cout << "Element is pushed....." << endl;
        }

        sizeQueue += 1;
    }

    void pop()
    {
        if (sizeQueue == 0)
        {
            cout << "Empty Queue....." << endl;
        }

        else
        {
            if (sizeQueue == 1)
            {
                start = nullptr;
                end = nullptr;
            }
            else
            {
                Node *temp = start;
                start = start->next;
                delete temp;
                cout << "Element is popped out" << endl;
                sizeQueue -= 1;
            }
        }
    }

    int topElQ()
    {
        if (sizeQueue == 0)
        {
            cout << "Empty Queue...." << endl;
        }
        return start->data;
    }

    int sizeOfQ()
    {
        return sizeQueue;
    }
};

//      <--------------------           STACK IMPLEMENTATION USING LINKED LIST          -------------------->

class StackImplUsingLL
{
    Node *topNode = nullptr;
    int sizeStack = 0;

public:
    void pushEL(int x)
    {
        Node *temp = new Node(x);

        temp->next = topNode;
        topNode = temp;

        sizeStack += 1;

        cout << "Element is pushed......" << endl;
    }

    void popEL()
    {
        if (topNode == nullptr)
        {
            cout << endl;
            cout << "Empty Stack !!!!" << endl;
            cout << endl;
            return;
        }

        Node *temp = topNode;

        cout << temp->data << " is popped out......" << endl;

        topNode = topNode->next;

        delete temp;

        sizeStack -= 1;
    }

    int topEL()
    {
        if (topNode == nullptr)
        {
            cout << endl;
            cout << "Empty Stack !!!!" << endl;
            cout << endl;
            return -1;
        }

        return topNode->data;
    }

    int sizeSt()
    {
        return sizeStack;
    }
};

class StackImpl
{
public:
    int topIndex = -1;

    int st[10];

    void push(int x)
    {
        if (topIndex < 10)
        {
            topIndex++;
            st[topIndex] = x;
            cout << "Elements is pushed...." << endl;
        }
        else
        {
            cout << endl;
            cout << "STACK IS FULL !!!!" << endl;
            cout << endl;
        }
    }

    void pop()
    {
        if (topIndex > -1)
        {
            cout << st[topIndex] << "  is popped out...." << endl;
            topIndex--;
        }
        else
        {
            cout << endl;
            cout << "STACK IS EMPTY !!!!" << endl;
            cout << endl;
        }
    }

    int top()
    {
        if (topIndex == -1)
        {
            cout << endl;
            cout << "STACK IS EMPTY !!!!" << endl;
            cout << endl;
        }
        else
        {
            cout << st[topIndex] << endl;
            return st[topIndex];
        }
    }

    int size()
    {
        cout << topIndex + 1 << endl;
        return topIndex + 1;
    }
};

//      <-----------------              QUEUE IMPLEMENTATION USING ARRAYS                   ------------------->

class QueueImpl
{
    int sizeQ = 10;
    int Q[10];
    int curSize = 0;
    int start = -1, end = -1;

    void push(int x)
    {
        if (curSize == sizeQ)
        {
            cout << endl;
            cout << "QUEUE IS FULL !!!!";
            cout << endl;
        }

        else if (curSize == 0)
        {
            start = 0;
            end = 0;
        }

        else
        {
            end = (end + 1) % sizeQ;
        }
        Q[end] = x;
        curSize += 1;
    }

    void pop()
    {
        if (curSize == 0)
        {
            cout << endl;
            cout << "QUEUE IS EMPTY !!!!";
            cout << endl;
        }

        // int el = Q[start];
        if (curSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % sizeQ;
        }
        curSize -= 1;
    }

    int top()
    {
        if (curSize == 0)
        {
            cout << endl;
            cout << "QUEUE IS EMPTY !!!!";
            cout << endl;
        }
        else
        {
            return Q[start];
        }
    }

    int sizeOf()
    {
        return curSize;
    }
};

int main()
{
    StackImplUsingLL nums;

    cout << endl;

    return 0;
}