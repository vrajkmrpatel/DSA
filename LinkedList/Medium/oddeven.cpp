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

Node *OddEvenlist(Node *head)
{
      //  time complexity: O(2N)
      // space complexity: O(N)

      // Node *temp = head;
      // vector<int> arr;
      // while (temp != NULL && temp->next != NULL)
      // {
      //       arr.push_back(temp->data);
      //       temp = temp->next->next;
      // }
      // if (temp)
      // {
      //       arr.push_back(temp->data);
      // }

      // temp = head->next;
      // while (temp != NULL && temp->next != NULL)
      // {
      //       arr.push_back(temp->data);
      //       temp = temp->next->next;
      // }
      // if (temp)
      // {
      //       arr.push_back(temp->data);
      // }

      // int i = 0;
      // temp = head;
      // while (temp != NULL)
      // {
      //       temp->data = arr[i];
      //       i++;
      //       temp = temp->next;
      // }
      // return head;

      // Optimal
      // time: O(N)
      // space: O(1)
      Node *odd = head;
      Node *even = head->next;
      Node *evenHead = head->next;

      while (even != NULL && even->next != NULL)
      {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
      }
      odd->next = evenHead;
      return head;
}

int main()
{
      vector<int> arr1 = {1, 2, 3, 4, 5, 6};

      Node *head = convertarrtoLL(arr1);
      traverseLL(head);

      // odd even linked list
      head = OddEvenlist(head);
      traverseLL(head);
}