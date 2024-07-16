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
   // for first node
   if(root == NULL) {
      root = new TreeNode(data);
      return root;
   }

   // rest nodes
   if(data > root->data) {
      root->right = insertIntoBST(root->right, data);
   }
   else {
      root->left = insertIntoBST(root->left, data);
   }

   return root;
}

void createBST(TreeNode*&root) {
   int data;
   cout << "Enter data : ";
   cin >> data;

   while(data != -1) {
      root = insertIntoBST(root, data);
      cout << "Enter data : ";
      cin >> data;
   }
}

TreeNode* minNode(TreeNode* root) {
   if(root == NULL) {
      return NULL;
   }

   TreeNode* temp = root;
   while(temp->left != NULL) {
      temp = temp->left;
   }
   return temp;
}

TreeNode* maxNode(TreeNode* root) {
   if(root == NULL) {
      return NULL;
   }

   TreeNode* temp = root;
   while(temp->right != NULL) {
      temp = temp->right;
   }
   return temp;
}

int main() {
   TreeNode* root = NULL;
   createBST(root);

   TreeNode* minValue = minNode(root);

   if(minValue == NULL) {
      cout << "Empty tree!";
   }else {
      cout << "minimum value : " << minValue->data << endl;
   }

   TreeNode* maxValue = maxNode(root);

   if(maxValue == NULL) {
      cout << "Empty tree!";
   }else {
      cout << "maximum value : " << maxValue->data << endl;
   }

   // input : 50 30 40 20 60 55 70 80 25 -1

}