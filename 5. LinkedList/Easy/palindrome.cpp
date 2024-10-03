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

Node *reverseLinkedList(Node *head)
{
      if (head == NULL || head->next == NULL)
            return head;
      Node *newHead = reverseLinkedList(head->next);
      Node *front = head->next;
      front->next = head;
      head->next = NULL;
      return newHead;
}

bool isPalindrome(Node *head)
{
      // Brute Force

      // stack<int> st;
      // Node *temp = head;
      // while (temp != NULL)
      // {
      //       st.push(temp->data);
      //       temp = temp->next;
      // }
      // temp = head;

      // while (temp != NULL)
      // {
      //       if (st.top() != temp->data)
      //       {
      //             return false;
      //       }
      //       st.pop();
      //       temp = temp->next;
      // }
      // return true;

      // OPTIMAL SOLUTION

      if (head == NULL || head->next == NULL)
      {
            return true;
      }
      Node *slow = head;
      Node *fast = head;

      while (fast->next != NULL && fast->next->next != NULL)
      {
            slow = slow->next;
            fast = fast->next->next;
      }

      Node *newHead = reverseLinkedList(slow->next);
      Node *first = head;
      Node *second = newHead;

      while (second != NULL)
      {

            if (first->data != second->data)
            {
                  reverseLinkedList(newHead);
                  return false;
            }
            first = first->next;
            second = second->next;
      }
      reverseLinkedList(newHead);
      return true;
}

int main()
{
      vector<int> arr = {1, 2, 3, 4,  2, 1};
      Node *head = convertarrtoLL(arr);
      traverseLL(head);

      if (isPalindrome(head))
      {
            cout << "IS PALINDROME" << endl;
      }
      else
      {
            cout << "NOT PALINDROME" << endl;
      }
}