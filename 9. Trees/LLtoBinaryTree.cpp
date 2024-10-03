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

struct TreeNode
{

      int data;
      TreeNode *left;
      TreeNode *right;
};

Node *convertarrtoLL(vector<int> &arr)
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
            cout << temp->data << ' ';
            temp = temp->next;
      }
      cout << endl;
}

TreeNode *newTreeNode(int data)
{

      TreeNode *temp = new TreeNode;
      temp->data = data;
      temp->left = temp->right = NULL;
      return temp;
}

void convertLLtoBinaryTree(Node *head, TreeNode *root)
{

      queue<TreeNode *> q;

      if (head == NULL)
      {

            root = NULL;
            return;
      }

      root = newTreeNode(head->data);
      q.push(root);

      head = head->next;

      while (head)
      {

            TreeNode *parent = q.front();
            q.pop();

            TreeNode *leftChild = NULL, *rightChild = NULL;
            leftChild = newTreeNode(head->data);
            q.push(leftChild);
            head = head->next;

            if (head)
            {

                  rightChild = newTreeNode(head->data);
                  q.push(rightChild);
                  head = head->next;
            }

            parent->left = leftChild;
            parent->right = rightChild;
      }
}

void inorderTraversal(TreeNode *root)
{
      
      if (root)
      {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
      }
}

int main()
{
      vector<int> arr1 = {10, 12, 15, 25, 30, 36};

      Node *head = convertarrtoLL(arr1);
      // traverseLL(head);

      TreeNode *root;
      convertLLtoBinaryTree(head, root);

      cout << "Inorder Traversal of the constructed Binary Tree is: \n";
      inorderTraversal(root);

      return 0;
}