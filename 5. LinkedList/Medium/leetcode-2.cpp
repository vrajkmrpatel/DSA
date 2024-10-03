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

int convertLLtoINT(Node *head)
{
    Node *temp = head;
    int i = 1;
    int num = 0;
    while (temp != NULL)
    {
        num = num + (temp->data) * i;
        i = i * 10;
        temp = temp->next;
    }
    return num;
}

Node *convertINTtoLL(int num)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while (num > 0)
    {
        int rem = num % 10;
        Node *newnode = new Node(rem);
        temp->next = newnode;
        temp = temp->next;
        num = num / 10;
    }
    return dummy->next;
}
// method - 2
Node *addTWOnumbers(Node *num1, Node *num2)
{
    Node *dummyHead = new Node(-1);
    Node *curr = dummyHead;
    Node *temp1 = num1;
    Node *temp2 = num2;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1)
            sum += temp1->data;
        if (temp2)
            sum += temp2->data;

        Node *newNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        curr->next = newNode;
    }

    return dummyHead->next;
}

Node *reverseLL(Node *head)
{
    Node *p = nullptr;
    Node *q = nullptr;

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

int main()
{
    vector<int> arr1 = {7, 5, 9, 4, 6};
    vector<int> arr2 = {8, 4};

    Node *l1 = convertarrtoLL(arr1);
    Node *l2 = convertarrtoLL(arr2);

    cout << "first list is ";
    traverseLL(l1);
    cout << "second list is ";
    traverseLL(l2);

    /* Method - 1
    int num1 = convertLLtoINT(l1);
    int num2 = convertLLtoINT(l2);
    cout << num1 << " " << num2 << " ";

    int sum = num1 + num2;
    cout << sum << " ";

    Node *ans = convertINTtoLL(sum);
    traverseLL(ans);
     */

    // Method - 2
    // Node *ans = addTWOnumbers(l1, l2);
    // traverseLL(ans);

    // gfg problem

    // reverse the list
    l1 = reverseLL(l1);
    l2 = reverseLL(l2);

    Node *ans = addTWOnumbers(l1, l2);

    // reverse the result
    ans = reverseLL(ans);
    cout << "Resultant list is ";
    traverseLL(ans);
}