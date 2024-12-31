#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

class Node
{
public:
      int key;
      int val;
      Node *next;
      Node *prev;

      Node(int _key, int _val)
      {
            key = _key;
            val = _val;
            next = prev = nullptr;
      }
};

class LRUCache
{
public:
      Node *head;
      Node *tail;
      int cap;
      unordered_map<int, Node *> mpp;

      LRUCache(int capacity)
      {
            cap = capacity;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
      }

      void insertAfterHead(Node *newnode)
      {
            Node *temp = head->next;
            newnode->next = temp;
            newnode->prev = head;
            head->next = newnode;
            temp->prev = newnode;
      }

      void deleteNode(Node *delnode)
      {
            Node *delprev = delnode->prev;
            Node *delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
      }

      int get(int key)
      {
            if (mpp.find(key) != mpp.end())
            {
                  Node *node = mpp[key];
                  mpp.erase(key);
                  deleteNode(node);
                  insertAfterHead(node);
                  mpp[key] = head->next;

                  return node->val;
            }
            return -1;
      }

      void put(int key, int value)
      {
            if (cap == 0)
                  return;

            if (mpp.find(key) != mpp.end())
            {
                  Node *node = mpp[key];
                  mpp.erase(key);
                  deleteNode(node);
                  delete node;
            }
            if (mpp.size() == cap)
            {
                  Node *toDelete = tail->prev;
                  mpp.erase(toDelete->key);
                  deleteNode(toDelete);
                  delete toDelete;
            }

            Node *newNode = new Node(key, value);
            insertAfterHead(newNode);
            mpp[key] = newNode;
      }

      ~LRUCache()
      {
            // Free all allocated nodes
            Node *curr = head;
            while (curr)
            {
                  Node *next = curr->next;
                  delete curr;
                  curr = next;
            }
      }
};

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      return 0;
}