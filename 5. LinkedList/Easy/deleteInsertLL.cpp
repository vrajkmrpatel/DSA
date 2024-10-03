#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;   // 4B
    Node *next; // 8B

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertarrtoLL(vector<int> &arr)
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

// Traverse a linkedList
void traverseLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

Node *deeleteHeadNode(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTailNode(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deleteK(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteVal(Node *head, int val)
{
    if (head == NULL)
        return head;
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// INSERTION IN LINKED LIST

Node *insertAtHead(Node *head, int val)
{
    Node *temp = new Node(val, NULL);
    temp->next = head;
    return temp;
}

Node *insertAtTail(Node *head, int val)
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

    Node *newNode = new Node(val, NULL);
    temp->next = newNode;
    return head;
}

Node *insertAtK(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(val);
        }
        else
        {
            return head;
        }
    }
    if (k == 1)
    {
        Node *temp = new Node(val, head);
        return temp;
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == k - 1)
        {
            Node *x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *insertBeforeVAL(Node *head, int el, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == val)
    {
        return new Node(el, head);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2,12, 3, 4,99};
    Node *head = convertarrtoLL(arr);
    traverseLL(head);

    // delete Head Node
    // head = deeleteHeadNode(head);
    // traverseLL(head);

    // // delete Tail Node
    // head = deleteTailNode(head);
    // traverseLL(head);

    // delete Kth Node
    // head = deleteK(head, 4);
    // traverseLL(head);

    // delete with value val
    // head = deleteVal(head, 4);
    // traverseLL(head);

    // insert at head node
    // head = new Node(100, head);
    // head = insertAtHead(head, 100);
    // traverseLL(head);

    // insert at Tail
    // head = insertAtTail(head, 100);
    // traverseLL(head);

    // insert at kth position
    // head = insertAtK(head, 100, 3);
    // traverseLL(head);

    // insert before the  value
    head = insertBeforeVAL(head, 100, 99);
    traverseLL(head);
}