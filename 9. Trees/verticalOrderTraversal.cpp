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

vector<vector<int>> verticalTraversal(Node *root)
{
      map<int, map<int, multiset<int>>> nodes;
      queue<pair<Node *, pair<int, int>>> todo;
      todo.push({root, {0, 0}});

      while (!todo.empty())
      {
            auto p = todo.front();
            todo.pop();

            Node *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->data);

            if (node->left)
                  todo.push({node->left, {x - 1, y + 1}});
            if (node->right)
                  todo.push({node->right, {x + 1, y + 1}});
      }
      vector<vector<int>> ans;
      for (auto p : nodes)
      {
            vector<int> col;
            for (auto q : p.second)
            {
                  col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
      }
      return ans;
}
int main()
{
      vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      Node *root = createBinaryTree(arr);

      vector<vector<int>> ans = verticalTraversal(root);
      for (auto it : ans)
      {
            for (auto num : it)
            {
                  cout << num << " ";
            }
            cout << endl;
      }
      return 0;
}
