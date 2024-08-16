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

TreeNode* inOrderToBst(int inOrder[], int s, int e) 
{
    if(s > e) {
        return NULL;
    }

    int mid = s + (e-s)/2;
    int elem = inOrder[mid];
    TreeNode* root = new TreeNode(elem);

    root->left = inOrderToBst(inOrder, s, mid-1);
    root->right = inOrderToBst(inOrder, mid+1, e);

    return root;
}

void levelOrder(TreeNode* root) 
{
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
            if(frontNode->left != NULL) q.push(frontNode->left);
            if(frontNode->right != NULL) q.push(frontNode->right);
        }
    }
}

void convertBstToDoublyLL(TreeNode* root, TreeNode*&head) 
{
    if(root == NULL) {
        return;
    }

    // reverse inOrder (RNL)
    convertBstToDoublyLL(root->right, head);

    root->right = head;
    if(head != NULL) head->left = root;
    head = root;

    convertBstToDoublyLL(root->left, head);
}

void printList(TreeNode* head) 
{
    TreeNode* temp = head;
    cout << endl << "Doubly linked list : ";
    while(temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->right;
    }
    cout << endl;
}

int main() {
    int inOrder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int start = 0;
    int end = size - 1;

    TreeNode* root = inOrderToBst(inOrder, start, end);
    levelOrder(root);

    TreeNode* head = NULL;
    convertBstToDoublyLL(root, head);
    printList(head);

}