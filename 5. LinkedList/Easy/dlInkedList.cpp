#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;   // 4B
    Node *next; // 8B
    Node *back; // 8B

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convertarrtoDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}
Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newtail = tail->back;
    tail->back = nullptr;
    newtail->next = nullptr;
    delete tail;

    return head;
}
Node *deleteKthNode(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    Node *kthnode = head;
    while (kthnode != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        kthnode = kthnode->next;
    }
    Node *prev = kthnode->back;
    Node *front = kthnode->next;

    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    else if (prev == NULL)
    {
        return deleteHead(head);
    }
    else if (front == NULL)
    {
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    kthnode->next = nullptr;
    kthnode->back = nullptr;

    delete kthnode;
    return head;
}
void deleteNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    delete temp;
}

// INSERTION BEFORE NODE
Node *insertBeforeHead(Node *head, int val)
{
    Node *temp = new Node(val, head, nullptr);
    head->back = temp;
    return temp;
}
Node *insertBeforeTail(Node *head, int val)
{
    if (head->next == NULL)
    {
        return insertBeforeHead(head, val);
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    Node *newnode = new Node(val, tail, prev);
    prev->next = newnode;
    tail->back = newnode;
    return head;
}
Node *insertBeforeK(Node *head, int val, int k)
{
    if (k == 1)
    {
        return insertBeforeHead(head, val);
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newnode = new Node(val, temp, prev);
    prev->next = newnode;
    temp->back = newnode;
    return head;
}

void insertAfterNode(Node *head, int pos, int data)
{

    int count = -1;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == pos)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        Node *newnode = new Node(data);
        newnode->back = temp;
        newnode->next = nullptr;
        temp->next = newnode;
        return;
    }
    Node *newnode = new Node(data);
    newnode->back = temp;
    temp->next->back = newnode;
    newnode->next = temp->next;
    temp->next = newnode;
}

void insertBeforeNode(Node *node, int val)
{
    Node *prev = node->back;
    Node *newnode = new Node(val, node, prev);
    prev->next = newnode;
    node->back = newnode;
}

void traversal(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {12, 4, 5,8};

    Node *head = convertarrtoDLL(arr);
    traversal(head);

    // DELETION IN DLL
    // DELETE HEAD NODE
    // head = deleteHead(head);
    // traversal(head);
    // DELETE TAIL NODE
    // head = deleteTail(head);
    // traversal(head);
    // DELETE KTH NODE
    // head = deleteKthNode(head, 4);
    // traversal(head);
    // DELETE NODE WITH VALUE
    // deleteNode(head->next->next->next);
    // traversal(head);

    // Insertion In DLL
    // insert before head node
    // head = insertBeforeHead(head, 100);
    // traversal(head);
    // insert before tail node
    // head = insertBeforeTail(head, 100);
    // traversal(head);
    // insert before kth element
    // head = insertBeforeK(head, 100, 2);
    // traversal(head);
    // insertBeforeNode(head->next->next, 100);
    // traversal(head);
    // insert After Node
    insertAfterNode(head, 0, 6);
    traversal(head);
}