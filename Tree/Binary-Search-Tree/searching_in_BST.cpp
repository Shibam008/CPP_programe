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

bool searching(TreeNode* root, int target) 
{
   // base case
   if(root == NULL) {
      return false;
   }

   // solve one case
   if(root->data == target) {
      return true;
   }

   // recurscive call
   bool leftAns = false;
   bool rightAns = false;

   if(target > root->data) {
      rightAns = searching(root->right, target);
   }
   else {
      leftAns = searching(root->left, target);
   }

   return (leftAns || rightAns);
}

int main() {
   TreeNode* root = NULL;
   createBST(root);
   
   int target;
   cout << endl << "Enter target value : ";
   cin >> target;

   while(target != -1) 
   {  
      bool ans = searching(root, target);

      if(ans == true) {
         cout << "Targer found" << endl;
      }else {
         cout << "Target not found!" << endl;
      }

      cout << "Enter target value (-1, for exit): ";
      cin >> target;
   }

}