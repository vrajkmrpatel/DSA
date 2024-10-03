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

Node *convertToArr(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newnode = new Node(arr[i], nullptr, temp);
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}

Node *reverseDLL(Node *head)
{
    // O(2N) Time complexity
    //  O(N) Space complexity
    stack<int> st;
    Node *temp = head;

    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

Node *reverseOptimalDLL(Node *head)
{
    // O(N) Time
    // O(1) Space
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *current = head;
    Node *last = nullptr;
    while (current != NULL)
    {
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    return last->back;
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
    // DLL
    vector<int> arr = {4, 3, 2, 1};
    Node *head = convertToArr(arr);
    traversal(head);

    // Brut force method
    // head = reverseDLL(head);
    // traversal(head);

    // Optimal Solution
    head = reverseOptimalDLL(head);
    traversal(head);
}