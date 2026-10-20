#include <iostream>

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

//          <----------------------       DELETING THE HEAD OF THE LINKED LIST             ------------------------>

Node *removesHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    free(temp); // OR you can use delete temp
    return head;
}

//          <----------------------       DELETING THE HEAD OF THE LINKED LIST             ------------------------>

Node *removesTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = nullptr;

    return head;
}

//          <-------------------       DELETING THE K'th ELEMENTOF THE LINKED LIST             -------------------->

Node *removeKthElement(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = temp->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

//          <----------------------       DELETING THE ELEMENT OF THE LINKED LIST BY VALUE            ------------------------>

Node *removeElement(Node *head, int ele)
{
    if (head == NULL)
        return head;
    if (head->data == ele)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == ele)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}
//          <-----------------             INSERTING NEW HEAD TO THE LINKED LIST                ------------------->

Node *insertHead(Node *head, int val)
{
    // Node *temp = new Node(val, head);
    // return temp;

    // also above line can be implemented in this way
    return new Node(val, head);
}

//          <-----------------             INSERTING NEW TAIL TO THE LINKED LIST                ------------------->

Node *insertTail(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(val);
    temp->next = newNode;

    return head;
}

//          <-----------------      INSERTING NEW ELEMENT AT KTH PLACE TO THE LINKED LIST       ------------------->

Node *insertPosition(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(val);
        }
        else
        {
            cout << "INVALID K !!!!" << endl;
        }
    }
    if (k == 1)
    {
        Node *newHead = new Node(val, head);
        return newHead;
    }

    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k - 1)
        {
            Node *x = new Node(val, temp->next);
            temp->next = x;

            break;
        }
        temp = temp->next;
    }
    return head;
}

//          <-----------------      INSERTING NEW ELEMENT BEFORE VALUE TO THE LINKED LIST       ------------------->

Node *insertBeforeValue(Node *head, int el, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == val)
    {
        Node *newHead = new Node(el, head);
        return newHead;
    }

    Node *temp = head;
    bool flag = false;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            flag = true;
            break;
        }
        temp = temp->next;
    }
    if (flag == false)
    {
        cout << "Element is not found !!!!" << endl;
    }
    return head;
}

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

//           <-------------------            FUNCTION TO PRINT ALL THE ELEMENTS OF THE LINKED LIST                   ------------------>

void print(Node *head)
{
    Node *temp = head;

    cout << endl;
    while (temp)
    {
        cout << temp->data << "   ";
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {12, 45, 67, 23, 57};
    Node *head = convertArr2LL(arr);

    print(head);

    int el;

    cout << endl;
    cin >> el;

    int val;

    cout << endl;
    cin >> val;

    head = insertBeforeValue(head, el, val);

    print(head);

    return 0;
}