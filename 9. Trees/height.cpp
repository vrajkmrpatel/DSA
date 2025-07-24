#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
      int data;
      TreeNode *left;
      TreeNode *right;

      TreeNode(int val)
      {
            data = val;
            left = right = nullptr;
      }
};

void inorder(TreeNode *root)
{
      if (root == NULL)
      {
            return;
      }

      inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
}

int heightOfTree(TreeNode *root)
{
      if (root == NULL)
            return 0;

      int lheight = heightOfTree(root->left);
      int rheight = heightOfTree(root->right);

      return max(lheight, rheight) + 1;
}
int main()
{

      TreeNode *root = new TreeNode(3);

      // left subtree
      root->left = new TreeNode(9);
      // root->left->left = new TreeNode(4);
      // root->left->right = new TreeNode(5);

      // right subtree
      root->right = new TreeNode(20);
      root->right->left = new TreeNode(15);
      root->right->right = new TreeNode(7);
      root->right->right->right = new TreeNode(23);

      // INORDER TRAVERSAL
      inorder(root);
      cout << endl;

      // HEIGHT OF THE TREE
      int ans = heightOfTree(root);
      cout << "Height of the tree is: " << ans << endl;

      return 0;
}