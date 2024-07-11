#include<bits/stdc++.h>
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
   root->left = createTree();
   root->right = createTree();
   return root;
}

void levelOrderTravarsal(TreeNode* root) {
   
   queue<TreeNode*> q;
   q.push(root);
   q.push(NULL);

   while( !q.empty() ) {
      TreeNode* frontNode = q.front();
      q.pop();

      if(frontNode == NULL) {
         cout << endl;
         if( !q.empty() ) 
         {
            q.push(NULL);
         }
      }
      else {
         cout << frontNode->data << " " ;

         if(frontNode->left != NULL) {
            q.push(frontNode->left);
         }
         if(frontNode->right != NULL) {
            q.push(frontNode->right);
         }
      }
   }
}

int searchInorder(int inOrder[], int n, int target) {
   for(int i=0; i<n; i++) {
      if(inOrder[i] == target){
         return i;
      }
   }
   return -1;
} 

TreeNode* constructionFromPreAndInOrder(int preOrder[], int inOrder[], int&preIndex, int inOrderStart, int inOrderEnd, int size) {
   // base case
   if(preIndex >= size || inOrderStart > inOrderEnd) {
      return NULL;
   }

   // solve one case
   int element = preOrder[preIndex];
   preIndex++;
   TreeNode* root = new TreeNode(element);
   
   //* search element into inorder array 
   int position = searchInorder(inOrder, size, element);

   root->left = constructionFromPreAndInOrder(preOrder, inOrder, preIndex, inOrderStart, position - 1, size);
   root->right = constructionFromPreAndInOrder(preOrder, inOrder, preIndex, position + 1, inOrderEnd, size);

   return root;
}

int main() {
   int inOrder[] = {10, 8, 6, 2, 4, 12};
   int preOrder[] = {2, 8, 10, 6, 4, 12};
   int size = sizeof(inOrder)/sizeof(int);
   int preOrderIdx = 0;
   int inOrderStartIdx = 0;
   int inOrderEndIdx = size - 1;

   TreeNode* root = constructionFromPreAndInOrder(preOrder, inOrder, preOrderIdx, inOrderStartIdx, inOrderEndIdx, size);
   levelOrderTravarsal(root);
   return 0;

}