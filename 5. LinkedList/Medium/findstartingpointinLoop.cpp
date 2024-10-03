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

Node *startingPointinLoop(Node* head)
{

      // Using Priority Queue

      // unordered_map<Node* , int> mpp;
      // Node* temp = head;

      // while(temp) {

      //       if(mpp.find(temp) != mpp.end()) {
      //             return temp;
      //       }
      //       mpp[temp] = 1;
      //       temp = temp->next;
      // }
      // return NULL;

      // Optimal 

      // step 1: detect a loop
      Node* slow = head;
      Node* fast = head;


      while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                  //step 2: find starting point
                  slow = head;
                  while(slow != fast) {
                        slow = slow->next;
                        fast = fast->next;
                  }
                  return slow;
            }
      }

      return NULL;


}

int main()
{
      Node *head = new Node(1);
      Node *first = new Node(2);
      Node *second = new Node(3);
      Node *third = new Node(4);
      Node *fourth = new Node(5);
      Node *five = new Node(6);
      Node *six = new Node(61);

      head->next = first;
      first->next = second;
      second->next = third;
      third->next = fourth;
      fourth->next = five;
      five->next = six;
      six->next = second;

      Node* ans = startingPointinLoop(head);
      traverseLL(ans);


      return 0;
}