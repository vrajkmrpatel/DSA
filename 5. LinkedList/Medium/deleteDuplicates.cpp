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

// remove duplicates from the list
Node *removeDuplicates(Node *head)
{
      Node *temp = head;
      Node *prev = NULL;

      while (temp != NULL)
      {
            int cnt = 0;

            while (temp != NULL && temp->next != NULL)
            {

                  if (temp->data == temp->next->data)
                  {
                        temp = temp->next;
                        cnt++;
                  }
                  else
                  {
                        break;
                  }
            }

            if (cnt > 0)
            {
                  if (prev != NULL)
                  {
                        prev->next = temp->next;
                        temp = prev->next;
                  }
                  else // if head & head->next are duplicate
                  {
                        // update head
                        head = temp->next;
                        temp = head;
                  }
            }
            else
            {
                  prev = temp;
                  temp = temp->next;
            }
      }
      return head;
}

int main()
{

      vector<int> arr = {23, 28, 28, 35, 49, 49, 53, 53};
      //      vector<int> arr = {11, 11, 11, 11, 75, 75};

      Node *head = convertarrtoLL(arr);
      traverseLL(head);

      head = removeDuplicates(head);
      traverseLL(head);
      return 0;
}