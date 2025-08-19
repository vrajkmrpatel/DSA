#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

Node *merge2Lists(Node *head1, Node *head2)
{
    Node *dummy = new Node(-1);
    Node *curr = dummy;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val <= head2->val)
        {
            curr->next = head1;
            head1 = head1->next;
        }
        else
        {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    if (head1)
    {
        curr->next = head1;
        head1 = head1->next;
    }

    if (head2)
    {
        curr->next = head2;
        head2 = head2->next;
    }
    return dummy->next;
}
Node *mergeKLists(vector<Node *> &lists)
{

    // // Simple Approach without HEAP
    // Node *res = nullptr;

    // // By traversing the whole list array and appending into res pointer
    // for (Node *node : lists)
    // {
    //     res = merge2Lists(res, node);
    // }
    // return res;

    // Using Priority Queue

    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i])
        {

            pq.push({lists[i]->val, lists[i]});
        }
    }

    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        if (it.second->next)
        {
            pq.push({it.second->next->val, it.second->next});
        }
        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
}

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
}

int main()
{

    int k = 3;

    vector<Node *> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);

    Node *head = mergeKLists(arr);

    printList(head);
    return 0;
}