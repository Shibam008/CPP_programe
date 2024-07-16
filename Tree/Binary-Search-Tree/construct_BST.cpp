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

void levelOrde(TreeNode* root) {
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
   levelOrde(root);

   // input : 50 30 40 20 60 55 70 80 25 -1

}