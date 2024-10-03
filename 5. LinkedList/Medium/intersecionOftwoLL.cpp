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

Node *collisonPoint(Node *shead, Node *lhead, int diff)
{

      while (diff)
      {
            diff--;
            lhead = lhead->next;
      }

      while (shead != lhead)
      {
            shead = shead->next;
            lhead = lhead->next;
      }
      return shead;
}
Node *intersecionOfLL(Node *head1, Node *head2)
{

      // Brute Force
      // unordered_map<Node *, int> mpp;

      // Node *temp = head1;

      // while (temp)
      // {

      //       mpp[temp] = 1;
      //       temp = temp->next;
      // }

      // temp = head2;

      // while (temp)
      // {
      //       if (mpp.find(temp) != mpp.end())
      //       {
      //             return temp;
      //       }
      //       temp = temp->next;
      // }
      // return NULL;

      // Node *t1 = head1;
      // Node *t2 = head2;

      // int cnt1 = 0;
      // while (t1)
      // {
      //       cnt1++;
      //       t1 = t1->next;
      // }

      // int cnt2 = 0;
      // while (t2)
      // {
      //       cnt2++;
      //       t2 = t2->next;
      // }

      // if (cnt1 < cnt2)
      // {
      //       return collisonPoint(head1, head2, cnt2 - cnt1);
      // }
      // else
      // {
      //       return collisonPoint(head2, head1, cnt1 - cnt2);
      // }

      // OPTIMAL APPROACH

      if (head1 == NULL || head2 == NULL)
      {
            return NULL;
      }
      Node *temp1 = head1;
      Node *temp2 = head2;

      while (temp1 != temp2)
      {

            temp1 = temp1->next;
            temp2 = temp2->next;

            if (temp1 == temp2)
                  return temp1;

            if (temp1 == NULL)
                  temp1 == head2;
            if (temp2 == NULL)
                  temp2 == head1;
      }
      return temp1;
}
int main()
{
      Node *head1 = new Node(1);
      Node *first = new Node(2);
      Node *second = new Node(3);
      Node *third = new Node(4);
      Node *fourth = new Node(5);
      Node *five = new Node(6);

      Node *head2 = new Node(66);
      Node *six = new Node(7);
      Node *seven = new Node(8);

      head1->next = first;
      first->next = second;
      second->next = third;
      third->next = fourth;
      fourth->next = five;
      five->next = nullptr;

      head2->next = six;
      six->next = seven;
      seven->next = third;

      traverseLL(head1);
      traverseLL(head2);

      Node *common = intersecionOfLL(head1, head2);
      traverseLL(common);

      return 0;
}