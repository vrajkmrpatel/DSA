#include <bits/stdc++.h>

using namespace std;

struct Node
{

      int data;
      Node *left;
      Node *right;

      Node(int val)
      {

            data = val;
            left = right = NULL;
      }
};

void inorder(Node *root)
{

      if (root == NULL)
      {
            return;
      }

      inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
}

void preorder(Node *root)
{

      if (root == NULL)
            return;

      cout << root->data << " ";
      preorder(root->left);
      preorder(root->right);
}
void postorder(Node *root)
{

      if (root == NULL)
            return;

      postorder(root->left);
      postorder(root->right);
      cout << root->data << " ";
}

vector<vector<int>> levelOrder(Node *root)
{
      vector<vector<int>> ans;

      if (root == NULL)
            return ans;

      queue<Node *> q;
      q.push(root);
      while (!q.empty())
      {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; i++)
            {
                  Node *node = q.front();
                  q.pop();

                  if (node->left != NULL)
                        q.push(node->left);
                  if (node->right != NULL)
                        q.push(node->right);

                  level.push_back(node->data);
            }
            ans.push_back(level);
      }
      return ans;
}
void printVector(const vector<int> &arr)
{

      for (auto num : arr)
      {
            cout << num << " ";
      }
      // cout << endl;
}
int main()
{
      Node *root = new Node(1);

      root->left = new Node(2);
      root->right = new Node(3);

      root->left->left = new Node(4);
      root->left->right = new Node(5);

      root->right->left = new Node(6);
      root->right->right = new Node(7);

      // INORDER TRAVERSAL
      cout << "INORDER : ";
      inorder(root);
      cout << endl;

      // PREORDER TRAVERSAL
      cout << "PREORDER : ";
      preorder(root);
      cout << endl;

      // POSTORDER TRAVERSAL
      cout << "POSTORDER : ";
      postorder(root);
      cout << endl;

      // LEVEL ORDER TRAVERSAL
      cout << "LEVEL ORDER : ";
      vector<vector<int>> ans = levelOrder(root);

      for (const vector<int> &level : ans)
      {
            printVector(level);
      }

      return 0;
}

// Tree

/*

            1
           / \
          2   3
         / \ / \
        4  5 6  7


*/