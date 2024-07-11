#include<bits/stdc++.h>
using namespace std;

// time & space complexity - O(n)

class TreeNode {
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* creatTree() {
    int data;
    cout << "Enter data for Node : " << endl;
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(data);
    //cout << "left child of Node : " << root->data <<endl;
    root->left = creatTree();
    //cout << "right child of Node : " << root->data <<endl;
    root->right = creatTree();

    return root;
}

void preOrderTraversal(TreeNode* root) {
    // base case
    if(root == NULL) {
        return;
    }
    // N-current node/ L-left node/ R-right node
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode* root) {
    // base case
    if(root == NULL) {
        return;
    }
    // L-left node / N-current node / R-right node
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    // base case
    if(root == NULL) {
        return;
    }
    // L-left node / R-right node / N-current node
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = creatTree();
    cout << endl << "Root Node : " << root->data << endl;

   // input = 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1

    cout << "Pre-order Traversal : ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-order Traversal : ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal : ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}

