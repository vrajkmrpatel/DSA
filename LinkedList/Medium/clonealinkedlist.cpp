#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
      int data;   // 4B
      Node *next; // 8B
      Node *random;

public:
      Node(int data1, Node *next1, Node* random1)
      {
            data = data1;
            next = next1;
            random = random1;
      }
      Node(int data1)
      {
            data = data1;
            next = nullptr;
            random = nullptr;
      }
};

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
      Node* head = new Node(7);
      head->next = new Node(13);
      head->random = nullptr;

      head->next->next = new Node(11);
      head->next->random = head;

      head->next->next->next = new Node(10);
      head->next->next->random = new Node(10);


      traverseLL(head);

      head = cloneLinkedList(head);
      traverseLL(head);
      return 0;
}