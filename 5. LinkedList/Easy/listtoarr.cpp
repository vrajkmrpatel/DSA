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

Node *reverseLinkedList(Node *head)
{
    Node *p = NULL;
    Node *q = NULL;

    while (head != NULL)
    {
        p = q;
        q = head;

        head = head->next;

        q->next = p;
    }
    head = q;
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
}
int LengthofLL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertarrtoLL(arr);

    // Traverse a linkedList
    // traverseLL(head);

    // cout << "\nReverse of the LL: ";
    // Node *reverse = reverseLinkedList(head);

    // Traverse a linkedList
    // traverseLL(reverse);

    // Length of the Linked list
    cout << LengthofLL(head);
}