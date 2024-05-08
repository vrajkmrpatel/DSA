#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
      int data;
      TreeNode *left;
      TreeNode *right;

      TreeNode() : data(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

TreeNode *createBinaryTree(vector<int> &arr)
{

      if (arr.empty())
            return NULL;
      TreeNode *root = new TreeNode(arr[0]);
      queue<TreeNode *> q;
      q.push(root);
      int i = 1;

      while (i < arr.size())
      {

            TreeNode *curr = q.front();
            q.pop();
            if (i < arr.size())
            {
                  curr->left = new TreeNode(arr[i++]);
                  q.push(curr->left);
            }
            if (i < arr.size())
            {
                  curr->right = new TreeNode(arr[i++]);
                  q.push(curr->right);
            }
      }
      return root;
}
void printTree(TreeNode *root)
{
      if (!root)
            return;
      // inorder
      printTree(root->left);
      cout << root->data << " ";
      printTree(root->right);
}

int main()
{
      vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
      TreeNode *root = createBinaryTree(arr);
      printTree(root);
      return 0;
}