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

      // 2 Pointer Solution

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

Node *mergeKsortedLL(vector<Node *> &lists)
{

      // vector<int> ans;
      // for (int i = 0; i < lists.size(); i++)
      // {

      //       Node *temp = lists[i];

      //       while (temp)
      //       {
      //             ans.push_back(temp->data);
      //             temp = temp->next;
      //       }
      // }

      // sort(ans.begin(), ans.end());

      // Node *head = convertarrtoLL(ans);
      // return head;

      // Node *head = lists[0];

      // for (int i = 1; i < lists.size(); i++)
      // {

      //       head = mergeLL(head, lists[i]);
      // }

      // return head;

      // Using Priority Queue

      priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

      for (int i = 0; i < lists.size(); i++)
      {
            if (lists[i])
            {

                  pq.push({lists[i]->data, lists[i]});
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
                  pq.push({it.second->next->data, it.second->next});
            }
            temp->next = it.second;
            temp = temp->next;
      }
      return dummyNode->next;
}

int main()
{

      vector<int> arr1 = {2, 4, 6};
      vector<int> arr2 = {1, 5};
      vector<int> arr3 = {1, 1, 3, 7};
      vector<int> arr4 = {8};

      Node *head1 = convertarrtoLL(arr1);
      Node *head2 = convertarrtoLL(arr2);
      Node *head3 = convertarrtoLL(arr3);
      Node *head4 = convertarrtoLL(arr4);

      traverseLL(head1);
      traverseLL(head2);
      traverseLL(head3);
      traverseLL(head4);

      vector<Node *> lists = {head1, head2, head3, head4};
      Node *head = mergeKsortedLL(lists);
      traverseLL(head);

      return 0;
}