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


TreeNode* bstFromInOrder(int inOrder[], int s, int e) {
    // base case
    if(s > e) {
        return NULL;
    }

    // handle one case
    int mid = s + (e-s)/2;
    int elem = inOrder[mid];
    TreeNode* root = new TreeNode(elem);
    
    // recursive call
    root->left = bstFromInOrder(inOrder, s, mid - 1);
    root->right = bstFromInOrder(inOrder, mid + 1, e);

    return root;
}


void levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty() ) {
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
            if(frontNode->left != NULL) q.push(frontNode->left);
            if(frontNode->right != NULL) q.push(frontNode->right);
        }
    }
}

int main() {
    int inOrder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int start = 0;
    int end = size - 1;

    TreeNode* root = bstFromInOrder(inOrder, start, end);
    levelOrder(root);
    return 0;
}





