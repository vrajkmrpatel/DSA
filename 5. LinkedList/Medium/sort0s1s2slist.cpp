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

Node *sort0s1s2slist(Node *head)
{
      //  time complexity: O(2N)
      // space complexity: O(1)

      // TWO PASS SOLUTION THAT'S WHY 2N
      // int cnt0 = 0, cnt1 = 0, cnt2 = 0;
      // Node *temp = head;
      // while (temp != NULL)
      // {
      //       if (temp->data == 0)
      //             cnt0++;
      //       else if (temp->data == 1)
      //             cnt1++;
      //       else
      //             cnt2++;
      //       temp = temp->next;
      // }

      // temp = head;
      // while (temp != NULL)
      // {
      //       if (cnt0)
      //       {
      //             temp->data = 0;
      //             cnt0--;
      //       }
      //       else if (cnt1)
      //       {
      //             temp->data = 1;
      //             cnt1--;
      //       }
      //       else
      //       {
      //             temp->data = 2;
      //             cnt2--;
      //       }
      //       temp = temp->next;
      // }
      // return head;

      // Optimal

      if (head == NULL || head->next == NULL)
            return head;

      Node *zeroHead = new Node(-1);
      Node *oneHead = new Node(-1);
      Node *twoHead = new Node(-1);

      Node *zero = zeroHead;
      Node *one = oneHead;
      Node *two = twoHead;

      Node *temp = head;
      while (temp)
      {

            if (temp->data == 0)
            {
                  zero->next = temp;
                  zero = temp;
            }
            else if (temp->data == 1)
            {
                  one->next = temp;
                  one = temp;
            }
            else
            {
                  two->next = temp;
                  two = temp;
            }
            temp = temp->next;
      }

      zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
      one->next = twoHead->next;
      two->next = NULL;

      Node *newHead = zeroHead->next;

      delete zeroHead;
      delete oneHead;
      delete twoHead;

      return newHead;
}

int main()
{
      vector<int> arr1 = {1, 2, 1, 2, 1, 2};

      Node *head = convertarrtoLL(arr1);
      traverseLL(head);

      // odd even linked list
      head = sort0s1s2slist(head);
      traverseLL(head);
}