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

bool isLeaf(Node* node)
{
      if((node->left == NULL) && (node->right == NULL))
      {
            return true;
      }
      return false;
}

void addLeftBoundary(Node* root, vector<int> &res)
{
      Node *curr = root->left;
      while(curr)
      {
            if(!isLeaf(curr))
                  res.push_back(curr->data);  
            if(curr->left)
                  curr = curr->left;
            else
                  curr = curr->right;
      }
}
void addRightBoundary(Node* root, vector<int> &res)
{
      vector<int> temp;
      Node *curr = root->right;
      while(curr)
      {
            if(!isLeaf(curr))
                  temp.push_back(curr->data);  
            if(curr->right)
                  curr = curr->right;
            else
                  curr = curr->left;
      }

      for (int i = temp.size() - 1; i>= 0; i--)
      {
            res.push_back(temp[i]);
      }
}

void addLeafNodes(Node* root, vector<int> &res)
{
      if(isLeaf(root)){
            res.push_back(root->data);
            return;
      }

      if(root->left)
            addLeafNodes(root->left, res);
      if(root->right)
            addLeafNodes(root->right, res);
}

vector<int> boundaryTraversal(Node *root)
{
      // code here
      vector<int> res;
      if(root == NULL)
            return res;
      
      if(!isLeaf(root))
            res.push_back(root->data);
      addLeftBoundary(root, res);
      addLeafNodes(root, res);
      addRightBoundary(root, res);
      return res;
}
int main()
{
      vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      Node *root = createBinaryTree(arr);

      vector<int> ans = boundaryTraversal(root);
      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}
