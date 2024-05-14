#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node() {
            this->next = NULL;
        }
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

Node* getStartingPosOfLoop(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow) {
            break;
        }
    }

    slow = head;
    while(fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // or fast
}

int main() {
    
}