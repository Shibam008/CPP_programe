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

TreeNode* deleteFromBST(TreeNode* root, int target) 
{
   if(root == NULL) {
      return NULL;
   }

   if(root->data == target) 
   {
      // 4 cases
      if(root->left == NULL && root->right == NULL) 
      {
         //* case 1 : leaf node
         delete root;
         return NULL;
      }
      else if(root->left != NULL && root->right == NULL) 
      {
         //* case 2 : left node non-null & right node NULL
         TreeNode* childSubTree = root->left;
         delete root;
         return childSubTree;
      }
      else if(root->left == NULL && root->right != NULL) 
      {
         //* case 2 : right node non-null & left node NULL
         TreeNode* childSubTree = root->right;
         delete root;
         return childSubTree;
      }
      else 
      {
         //* case 4 : left & right both are non-null

         // find max of left sub tree
         // then replace that maxi with root node
         TreeNode* maxi = maxNode(root->left);
         root->data = maxi->data;

         // delete actual maxi
         root->left = deleteFromBST(root->left, maxi->data);
      } 
   }
   else if(root->data > target) 
   {
      // go to left
      root->left = deleteFromBST(root->left, target);
   }
   else 
   {
      // go to right
      root->right = deleteFromBST(root->right, target);
   }
}

int main() {
   TreeNode* root = NULL;
   createBST(root);
   cout << endl;
   levelOrder(root);

   int target;
   cout << endl << "Enter target for deletion : ";
   cin >> target;

   while(target != -1) {
      root = deleteFromBST(root, target);
      cout << endl << "Printing tree by level order travarsal : " << endl;
      levelOrder(root);

      cout << "Enter target for deletion : ";
      cin >> target;
   }

   // input : 50 30 40 20 60 55 70 80 25 -1

}