#include<bits/stdc++.h>
using namespace std;

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
    cout << "Enter data : " << endl;
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(data);
    root->left = creatTree();
    root->right = creatTree();

    return root;
}

void levelOrderTrvrsl(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while( !q.empty() ) {
        TreeNode* frontNode = q.front();
        q.pop();

        cout << frontNode->data << " ";

        if(frontNode->left != NULL) {
            q.push(frontNode->left);
        }
        if(frontNode->right != NULL) {
            q.push(frontNode->right);
        }
    }
}

void levelOrderTrvrsl_LevelByLevel(TreeNode* root) {
    
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty() ) {
        TreeNode* frontNode = q.front();
        q.pop();

        if(frontNode == NULL) {
            cout << endl;
            if(!q.empty()) 
            {
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
    TreeNode* root = creatTree();
    cout << "Root : " << root->data << endl;
    cout << endl << "level order : " << endl;
    //levelOrderTrvrsl(root);
    levelOrderTrvrsl_LevelByLevel(root);

    // input = 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1
}

