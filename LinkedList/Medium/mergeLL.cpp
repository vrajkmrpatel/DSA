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
Node *mergeLL(Node *head1, Node *head2)
{

      // Naive Solution
      // vector<int> ans;
      // Node *temp1 = head1;
      // Node *temp2 = head2;

      // while (temp1)
      // {
      //       ans.push_back(temp1->data);
      //       temp1 = temp1->next;
      // }
      // while (temp2)
      // {
      //       ans.push_back(temp2->data);
      //       temp2 = temp2->next;
      // }

      // sort(ans.begin(), ans.end());

      // Node *head = convertarrtoLL(ans);
      // return head;

      // 2 Pointer Solution

      if (head1 == NULL)
      {
            return head2;
      }
      if (head2 == NULL)
      {
            return head1;
      }

      Node *temp1 = head1;
      Node *temp2 = head2;

      Node *dummyNode = new Node(-1);
      Node *temp = dummyNode;

      while (temp1 != NULL && temp2 != NULL)
      {

            if (temp1->data < temp2->data)
            {
                  temp->next = temp1;
                  temp = temp1;
                  temp1 = temp1->next;
            }
            else
            {
                  temp->next = temp2;
                  temp = temp2;
                  temp2 = temp2->next;
            }
      }

      if (temp1)
      {
            temp->next = temp1;
      }
      else
      {
            temp->next = temp2;
      }

      return dummyNode->next;
}

int main()
{

      vector<int> l1 = {};
      vector<int> l2 = {1, 3, 3, 6, 11, 14};

      Node *head1 = convertarrtoLL(l1);
      Node *head2 = convertarrtoLL(l2);
      traverseLL(head1);
      traverseLL(head2);

      Node *head = mergeLL(head1, head2);
      traverseLL(head);

      return 0;
}