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

Node *removeDuplicates(Node *head)
{

      Node *temp = head;

      while (temp != NULL && temp->next != NULL)
      {

            Node *nextNode = temp->next;

            while (nextNode != NULL && nextNode->data == temp->data)
            {
                  Node *duplicate = nextNode;
                  nextNode = nextNode->next;
                  delete duplicate;
            }
            temp->next = nextNode;
            if (nextNode)
            {
                  nextNode->back = temp;
            }
            temp = temp->next;
      }

      return head;
}

int main()
{
      // DLL
      vector<int> arr = {1, 1, 1, 2, 3, 3, 4};
      Node *head = convertToArr(arr);
      traversal(head);

      Node *ans = removeDuplicates(head);
      traversal(ans);
}