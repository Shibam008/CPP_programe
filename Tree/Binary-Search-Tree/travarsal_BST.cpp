#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
   int data;
   TreeNode *left, *right;

   TreeNode(int value) {
      this->data = value;
      this->left = NULL;
      this->right = NULL;
   }
};

TreeNode* insertIntoBST(TreeNode* root, int data) {
   // first node creation
   if(root == NULL) {
      root = new TreeNode(data);
      return root;
   }

   if(data > root->data) {
      root->right = insertIntoBST(root->right, data);
   }
   else {
      root->left = insertIntoBST(root->left, data);
   }

   return root;
}

void createBST(TreeNode*&root) {
   cout << "Enter data : ";
   int data;
   cin >> data;

   while(data != -1) {
      root = insertIntoBST(root, data);
      cout << "Enter data";
      cin >> data;
   }
}

void preOrder(TreeNode* root) {
   if(root == NULL) {
      return;
   }
   cout << root->data << " ";
   preOrder(root->left);
   preOrder(root->right);
}

void inOrder(TreeNode* root) {
   if(root == NULL) {
      return;
   }
   inOrder(root->left);
   cout << root->data << " ";
   inOrder(root->right);
}

void postOrder(TreeNode* root) {
   if(root == NULL) {
      return;
   }
   postOrder(root->left);
   postOrder(root->right);
   cout << root->data << " ";
}

void levelOrder(TreeNode* root) {
   queue<TreeNode*> q;
   q.push(root);
   q.push(NULL);

   while(!q.empty()) {
      TreeNode* frontNode = q.front();
      q.pop();

      if(frontNode == NULL) {
         cout << endl;
         if(!q.empty()) {
            q.push(NULL);
         }
      }
      else {
         cout << frontNode->data << " ";

         if(frontNode->left != NULL) {
            q.push(frontNode->left);
         }

         if(frontNode->right != NULL) {
            q.push(frontNode->right);
         }
      }
   }
}

int main() {
   TreeNode* root = NULL;
   createBST(root);

   cout << endl << "level order travarsal : " << endl;
   levelOrder(root);

   cout << endl << "In order travarsal : ";
   inOrder(root);

   cout << endl << "Pre order travarsal : ";
   preOrder(root);

   cout << endl << "Post order travarsal : ";
   postOrder(root);

   // input : 50 30 40 20 60 55 70 80 25 -1

}