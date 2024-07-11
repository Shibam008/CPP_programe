#include<iostream>
using namespace std;

class TreeNode {
public:
   int data;
   TreeNode *left, *right;

   TreeNode(int data) {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
   }
};

TreeNode* createTree() {
   int data;
   cout<< "Enter data : ";
   cin >> data;

   if(data == -1) {
      return NULL;
   }

   TreeNode* root = new TreeNode(data);

   cout << "Enter data for left of node " << data << endl;
   root->left = createTree();

   cout << "Enter data for right of node " << data << endl;
   root->right = createTree();

   return root;
}

int main() {
   TreeNode* root = createTree();
   cout << "Root node of the tree : " << root->data << endl;
}