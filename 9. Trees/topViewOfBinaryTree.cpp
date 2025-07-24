#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
      int data;
      Node *left;
      Node *right;

      Node() : data(0), left(nullptr), right(nullptr) {}
      Node(int x) : data(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

Node *createBinaryTree(vector<int> &arr)
{

      if (arr.empty())
            return NULL;
      Node *root = new Node(arr[0]);
      queue<Node *> q;
      q.push(root);
      int i = 1;

      while (i < arr.size())
      {

            Node *curr = q.front();
            q.pop();
            if (i < arr.size())
            {
                  curr->left = new Node(arr[i++]);
                  q.push(curr->left);
            }
            if (i < arr.size())
            {
                  curr->right = new Node(arr[i++]);
                  q.push(curr->right);
            }
      }
      return root;
}
void printTree(Node *root)
{
      if (!root)
            return;
      // inorder
      printTree(root->left);
      cout << root->data << " ";
      printTree(root->right);
}

bool isLeaf(Node *node)
{
      if ((node->left == NULL) && (node->right == NULL))
      {
            return true;
      }
      return false;
}

vector<int> topViewOfBinaryTree(Node *root)
{
      // code here
      vector<int> res;
      if (root == NULL)
            return res;
      map<int, int> mpp;
      queue<pair<Node *, int>> q;
      q.push({root, 0});
      while (!q.empty())
      {
            auto p = q.front();
            q.pop();

            Node *node = p.first;
            int line = p.second;

            if (mpp.find(line) == mpp.end())
            {
                  mpp[line] = node->data;
            }

            if (node->left != NULL)
                  q.push({node->left, line - 1});
            if (node->right != NULL)
                  q.push({node->right, line + 1});
      }

      for (auto it : mpp)
      {
            res.push_back(it.second);
      }
      return res;
}
int main()
{
      vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
      Node *root = createBinaryTree(arr);

      vector<int> ans = topViewOfBinaryTree(root);
      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}
