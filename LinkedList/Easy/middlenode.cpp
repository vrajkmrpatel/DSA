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

Node *findMiddleofLL(Node *head)
{
    // slow and fast pointer
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast -> next->next;
        slow = slow->next;
    }
    return slow;

    // Naive Solution
    // TC: 2 pass solution 
    // Node *temp = head;
    // int count = 0;
    // while (temp != NULL)
    // {
    //     count++;
    //     temp = temp->next;
    // }

    // temp = head;
    // int mid = count / 2 + 1;
    // // cout << count << ' ' << mid << endl;
    // while (temp != NULL)
    // {
    //     mid = mid - 1;
    //     if (mid == 0)
    //     {
    //         break;
    //     }
    //     temp = temp->next;
    // }

    // return temp;
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

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertarrtoLL(arr);
    cout << "List is: ";
    traverseLL(head);

    head = findMiddleofLL(head);
    cout << "Output: ";
    traverseLL(head);
}