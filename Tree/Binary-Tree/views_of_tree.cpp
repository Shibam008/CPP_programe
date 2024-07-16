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
   cout << "Enter data : " << endl;
   cin >> data; 

   if(data == -1) {
      return NULL;
   }

   TreeNode* root = new TreeNode(data);
   root->left = createTree();
   root->right = createTree();
}

void preOrder(TreeNode* root) {  //! used to printing left and right view
   if(root == NULL) {
      return;
   }
   cout << root->data << " ";
   preOrder(root->left);
   preOrder(root->right);
}

void levelOrder(TreeNode* root) {  //! used to print top view
   queue<TreeNode*> q;
   q.push(root);
   q.push(NULL);

   while(!q.empty()) 
   {
      TreeNode* frontNode = q.front();
      q.pop();

      if(frontNode == NULL) {
         cout << endl;
         if( !q.empty() ) {
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

void printLeftView(TreeNode* root, int level, vector<int>&leftView) {
   // base case
   if(root == NULL) {
      return;
   }

   if(level == leftView.size()) {
      leftView.push_back(root->data);
   }
   printLeftView(root->left, level + 1, leftView);
   printLeftView(root->right, level + 1, leftView);
}

void printRightView(TreeNode* root, int level, vector<int>&rightView) {
   // base case
   if(root == NULL) {
      return;
   }

   if(level == rightView.size()) {
      rightView.push_back(root->data);
   }
   printRightView(root->right, level + 1, rightView);
   printRightView(root->left, level + 1, rightView);
}



void printTopView(TreeNode* root) 
{
   // hd = horizontal distance

   map<int, int> hdToNodemap;
   queue <pair<TreeNode*, int> > q;
   q.push(make_pair(root, 0));

   while( !q.empty() )
   {
      pair<TreeNode*, int> temp = q.front();
      q.pop();

      TreeNode* frontNode = temp.first;
      int hd = temp.second;

      //* if there is no entry for hd in map, then creat a new entry
      if(hdToNodemap.find(hd) == hdToNodemap.end()) {
         hdToNodemap[hd] = frontNode->data;
      }

      //* check childs
      if(frontNode->left != NULL) {
         q.push(make_pair(frontNode->left, hd - 1));
      }
      if(frontNode->right != NULL) {
         q.push(make_pair(frontNode->right, hd + 1));
      }
   }
   cout << endl << "Top view of the tree : ";
   for(auto i : hdToNodemap) {
      cout << i.second << " ";
   }
}



void printBottomView(TreeNode* root) 
{
   // hd = horizontal distance

   map<int, int> hdToNodemap;
   queue <pair<TreeNode*, int> > q;
   q.push(make_pair(root, 0));

   while( !q.empty() )
   {
      pair<TreeNode*, int> temp = q.front();
      q.pop();

      TreeNode* frontNode = temp.first;
      int hd = temp.second;

      //* overwrite answers so than deeper nodes can be stored
      
      hdToNodemap[hd] = frontNode->data;

      //* check childs
      if(frontNode->left != NULL) {
         q.push(make_pair(frontNode->left, hd - 1));
      }
      if(frontNode->right != NULL) {
         q.push(make_pair(frontNode->right, hd + 1));
      }
   }

   cout << endl << "Bottom view of the tree : ";
   for(auto i : hdToNodemap) {
      cout << i.second << " ";
   }
}


int main() {
   //* input 
   /*
   10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
   */ 

   TreeNode* root = createTree();
   levelOrder(root);

   vector<int> leftView;

   cout << endl << "left view of tree : ";
   printLeftView(root, 0, leftView);
   for(int i=0; i<leftView.size(); i++) {
      cout << leftView[i] << " ";
   }
   

   vector<int> rightView;

   cout << endl << "right view of tree : ";
   printRightView(root, 0, rightView);
   for(int i=0; i<rightView.size(); i++) {
      cout << rightView[i] << " ";
   }

   printTopView(root);
   printBottomView(root);
}