#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
      int data;   // 4B
      Node *next; // 8B
      Node *back; // 8B

public:
      Node(int data1, Node *next1, Node *back1)
      {
            data = data1;
            next = next1;
            back = back1;
      }
      Node(int data1)
      {
            data = data1;
            next = nullptr;
            back = nullptr;
      }
};

Node *convertToArr(vector<int> &arr)
{
      Node *head = new Node(arr[0]);
      Node *temp = head;

      for (int i = 1; i < arr.size(); i++)
      {
            Node *newnode = new Node(arr[i], nullptr, temp);
            temp->next = newnode;
            temp = newnode;
      }
      return head;
}

void traversal(Node *head)
{
      while (head != NULL)
      {
            cout << head->data << " ";
            head = head->next;
      }
      cout << endl;
}

vector<pair<int, int>> findpairwithdll(Node *head, int target)
{

      // brute force
      // time complexity : O(N^2)
      // Node *temp1 = head;

      // vector<pair<int, int>> ans;

      // while (temp1 != NULL)
      // {
      //       Node *temp2 = temp1->next;

      //       while (temp2 != NULL && temp1->data + temp2->data <= target)
      //       {

      //             if (temp1->data + temp2->data == target)
      //             {

      //                   ans.push_back({temp1->data, temp2->data});
      //             }

      //             temp2 = temp2->next;
      //       }
      //       temp1 = temp1->next;
      // }

      // return ans;

      // Linked list is sorted
      // Two pointer approach

      vector<pair<int, int>> ans;

      Node *left = head;
      Node *tail = head;

      while (tail->next != NULL)
      {

            tail = tail->next;
      }

      Node *right = tail;

      while (left->data < right->data)
      {

            int sum = left->data + right->data;

            if (sum == target)
            {
                  ans.push_back({left->data, right->data});

                  left = left->next;
                  right = right->back;
            }
            else if (sum < target)
            {
                  left = left->next;
            }
            else
            {
                  right = right->back;
            }
      }
      return ans;
}

int main()
{
      // DLL
      vector<int> arr = {1, 2, 3, 4, 9};
      Node *head = convertToArr(arr);
      traversal(head);

      vector<pair<int, int>> ans = findpairwithdll(head, 5);

      for (auto it : ans)
      {
            cout << "(" << it.first << "," << it.second << ")" << ",";
      }
}