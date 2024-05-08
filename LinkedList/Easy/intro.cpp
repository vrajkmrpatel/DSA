#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data; // 4B
    Node *next; //8B

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

int main()
{
    vector<int> arr = {2, 5, 8, 7};

    Node *y = new Node(arr[0], nullptr);
    cout << "Data: " << y->data << endl;
    cout << "Next:" << y->next;

    cout << endl;
    Node *z = new Node(arr[1]);
    cout << "Data: " << z->data << endl;
    cout << "Next:" << z->next;
}