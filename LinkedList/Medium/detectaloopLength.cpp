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

int detectLength(Node* slow, Node* fast) {

      int count = 1;
      fast = fast->next;

      while(slow != fast) {
            count++;
            fast = fast->next;
      }
      return count;
}

int detectALoopLength(Node *head)
{

      // Brute Force Approach

      // unordered_map<Node *, int> mpp;
      // int timer = 1;
      // Node *temp = head;

      // while (temp != NULL)
      // {

      //       if (mpp.find(temp) != mpp.end())
      //       {
      //             int val = mpp[temp];
      //             return timer - val;
      //       }
      //       mpp[temp] = timer;
      //       timer++;
      //       temp = temp->next;
      // }
      // return 0;

      // Optimal

      Node *slow = head;
      Node *fast = head;

      while (fast != NULL && fast->next != NULL)
      {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                  return detectLength(slow,fast);
            }
      }
      return 0;
}


int main()
{

      Node *head = new Node(1);
      Node *first = new Node(2);
      Node *second = new Node(3);
      Node *third = new Node(4);
      Node *third1 = new Node(44);
      Node *third2 = new Node(45);
      Node *fourth = new Node(5);
      Node *five = new Node(6);
      Node *six = new Node(61);

      head->next = first;
      first->next = second;
      second->next = third;
      third->next = third1;
      third1->next = third2;
      third2->next = fourth;
      fourth->next = five;
      five->next = six;
      six->next = second;

      int length = detectALoopLength(head);
      cout << "Length of the loop is: " << length << endl;

      return 0;
}