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
vector<vector<int>> zigzagLevelOrderTraversal(Node *root)
{
      vector<vector<int>> res;
      if (root == NULL)
            return res;
      queue<Node *> q;
      q.push(root);
      bool flag = true;
      while (!q.empty())
      {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++)
            {
                  Node *node = q.front();
                  q.pop();

                  // condition
                  int index = (flag) ? i : (size - 1 - i);
                  level[index] = node->data;

                  if (node->left)
                        q.push(node->left);
                  if (node->right)
                        q.push(node->right);
            }

            flag = !flag;
            res.push_back(level);
      }
      return res;
}

int main()
{
      vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      Node *root = createBinaryTree(arr);

      vector<vector<int>> ans = zigzagLevelOrderTraversal(root);
      for (auto it : ans)
      {
            for (int num : it)
            {
                  cout << num << " ";
            }
            cout << endl;
      }
      return 0;
}
