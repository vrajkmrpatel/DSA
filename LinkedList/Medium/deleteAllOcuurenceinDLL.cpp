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

void traversal(Node *head)
{
      while (head != NULL)
      {
            cout << head->data << " ";
            head = head->next;
      }
      cout << endl;
}

Node *deleteAllOccurenceOfDLL(Node *head, int key)
{

      Node *temp = head;

      while (temp)
      {
            if (temp->data == key)
            {

                  if (temp == head)
                  {
                        head = head->next;
                  }
                  Node *nextNode = temp->next;
                  Node *prevNode = temp->back;

                  if (nextNode)
                        nextNode->back = prevNode;
                  if (prevNode)
                        prevNode->next = nextNode;

                  delete temp;
                  temp = nextNode;
            }
            else
            {
                  temp = temp->next;
            }
      }

      return head;
}
int main()
{
      // DLL
      vector<int> arr = {10, 4, 10, 10, 6, 10};
      Node *head = convertToArr(arr);
      traversal(head);

      head = deleteAllOccurenceOfDLL(head, 10);
      traversal(head);
}