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

Node *reverseLL(Node *head)
{
      // using stack data structure
      // time: O(2N)
      // space: O(N)
      // stack<int> st;

      // Node *temp = head;
      // while (temp)
      // {
      //       st.push(temp->data);
      //       temp = temp->next;
      // }

      // temp = head;
      // while (temp)
      // {
      //       temp->data = st.top();
      //       st.pop();
      //       temp = temp->next;
      // }
      // return head;

      // Optimal solution

      // Node *temp = head;
      // Node *prev = NULL;

      // while (temp != NULL)
      // {
      //       Node* front = temp->next;
      //       temp->next = prev;
      //       prev = temp;
      //       temp = front;
      // }
      // return prev;

      // Recursion Approach

      if (head == NULL || head->next == NULL)
      {
            return head;
      }

      Node *newHead = reverseLL(head->next);
      Node *front = head->next;
      front->next = head;
      head->next = NULL;
      return newHead;
}

int main()
{
      vector<int> arr1 = {1, 2, 3, 4, 5, 6};

      Node *head = convertarrtoLL(arr1);
      traverseLL(head);

      // odd even linked list
      head = reverseLL(head);
      traverseLL(head);
}