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

Node *removeNthNode(Node *head, int n)
{
    // int count = 0;
    // Node *temp = head;

    // while (temp != NULL)
    // {
    //     count++;
    //     temp = temp->next;
    // }

    // if (count == n)
    // {
    //     Node *newHead = head->next;
    //     delete head;
    //     return newHead;
    // }
    // int res = count - n;
    // temp = head;
    // while (temp != NULL)
    // {
    //     res--;
    //     if (res == 0)
    //     {
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // Node *delNode = temp->next;
    // temp->next = temp->next->next;
    // delete delNode;
    // return head;

    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == NULL)
        return head->next;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
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

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertarrtoLL(arr);
    traverseLL(head);

    head = removeNthNode(head, 5);
    traverseLL(head);
}