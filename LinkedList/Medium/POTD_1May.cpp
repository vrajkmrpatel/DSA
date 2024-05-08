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

Node *convertarrtoLL(vector<char> &arr)
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
            cout << char(temp->data) << ' ';
            temp = temp->next;
      }
      cout << endl;
}
bool isVowel(char ch) {

      if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'){
            return true;
      }
      else {
            return false;
      }
}
Node* solve(Node* head) {

      Node* vowelHead = new Node('#');
      Node* consHead = new Node('#');
      Node* currVowel = vowelHead;
      Node* currCons = consHead;

      Node* temp = head;

      while(temp) {
            if(isVowel(temp->data)) {
                  currVowel->next = temp;
                  currVowel = currVowel->next;
            }
            else {
                  currCons->next = temp;
                  currCons = currCons->next;

            }
            temp = temp->next;
      }
      currVowel->next = NULL;
      currCons->next = NULL;

      currVowel->next = consHead->next;

      return vowelHead->next;

}

int main() 
{

      vector<char> arr = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
      Node *head = convertarrtoLL(arr);
      traverseLL(head);

      head = solve(head);
      traverseLL(head);

      return 0;
}