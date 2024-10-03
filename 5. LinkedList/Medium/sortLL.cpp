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

Node *findMiddleofLL(Node *head)
{
      // slow and fast pointer
      Node *slow = head;
      Node *fast = head->next;

      while (fast != NULL && fast->next != NULL)
      {
            slow = slow->next;
            fast = fast->next->next;
      }
      return slow;
}
Node *mergeLL(Node *head1, Node *head2)
{

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

Node *sortLL(Node *head)
{

      // // Brute Force Approach
      // // O(N + NlogN + N) time
      // // O(N) space

      // vector<int> tempArr;
      // Node *temp = head;

      // while (temp)
      // {
      //       tempArr.push_back(temp->data);
      //       temp = temp->next;
      // }

      // sort(tempArr.begin(), tempArr.end());

      // // temp = head;
      // // int i = 0;
      // // while (temp)
      // // {
      // //       temp->data = tempArr[i];
      // //       temp = temp->next;
      // //       i += 1;
      // // }

      // head = convertarrtoLL(tempArr);

      // return head;

      // Merge Sort in LL

      if (head == NULL || head->next == NULL)
      {
            return head;
      }

      Node *middle = findMiddleofLL(head);
      Node *leftHead = head;
      Node *rightHead = middle->next;

      middle->next = NULL;

      leftHead = sortLL(leftHead);
      rightHead = sortLL(rightHead);

      return mergeLL(leftHead, rightHead);
}
int main()
{

      vector<int> arr = {3, 4, 2, 1, 5};
      Node *head = convertarrtoLL(arr);
      traverseLL(head);

      head = sortLL(head);
      traverseLL(head);

      return 0;
}