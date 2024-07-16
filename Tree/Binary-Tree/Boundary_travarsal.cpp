#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
   int data;
   TreeNode *left, *right;

   TreeNode(int data) {
      this->data  = data;
      this->left = NULL;
      this->right = NULL;
   }
};

TreeNode* createTree() {
   int data;
   cout << "Enter data : " << endl;
   cin >> data;

   if(data == -1) {
      return NULL;
   }

   TreeNode* root = new TreeNode(data);
   root->left = createTree();
   root->right = createTree();
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
         if(!q.empty())
         {
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

//! we will solve this question by breaking it into 3 functions
/*
   1. print left boundary
   2. print leaf boundary
   3. print right boundary
*/

void printLeftBoundary(TreeNode* root) {
   // base cases
   if(root == NULL) {
      return;
   }
   if(root->left == NULL && root->right == NULL) {
      return; //! avoiding leaf node
   }

   cout << root->data << " ";

   if(root->left != NULL) {
      printLeftBoundary(root->left);
   }else {
      printLeftBoundary(root->right);
   }
}

void printLeafBoundary(TreeNode* root) {
   if(root == NULL) {
      return;
   }

   if(root->left == NULL && root->right == NULL) {
      cout << root->data <<" ";
   }
   printLeafBoundary(root->left);
   printLeafBoundary(root->right);
}

void printRightBoundary(TreeNode* root) {
   // base cases
   if(root == NULL) {
      return;
   }
   if(root->left == NULL && root->right == NULL) {
      return; //! avoiding leaf node
   }

   if(root->right != NULL) {
      printRightBoundary(root->right);
   }else {
      printRightBoundary(root->left);
   }

   cout << root->data << " ";
}

void boundaryTravarsal(TreeNode* root) {
   if(root == NULL) {
      return;
   }

   cout << root->data << " ";
   printLeftBoundary(root->left);
   printLeafBoundary(root->left);
   printLeafBoundary(root->right);
   printRightBoundary(root->right);
}


int main() {
   /*
   10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
   */
   
   TreeNode* root = createTree();
   levelOrder(root);
   boundaryTravarsal(root);
}