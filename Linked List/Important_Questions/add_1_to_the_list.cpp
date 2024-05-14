#include <iostream>
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

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->next = NULL;
        tail = newNode;
    }
}

Node* reverseList(Node* head) {
    
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

void addOne(Node* &head) {
    // reverse the list;
    head = reverseList(head);
    
    
    // add 1 to the head
    int carry = 1;
    Node* temp = head;
    
    while(temp->next != NULL) { // loop will handle before the last node
        int totalSum = temp->data + 1;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
        temp = temp->next;
        if(carry == 0) break;
    }

    // Handle last node
    if(carry != 0) {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
        if(carry != 0) {
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
    }

    // reverse again
    head = reverseList(head);
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    cout<<"Linked List :  ";
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 9);
    printLL(head);
    cout<<endl;

    cout<<"Added one '1': ";
    addOne(head);
    printLL(head);
    cout<<endl<<endl;

    // cout<<"Reversed Linked List : ";
    // head = reverseList(head);  // for getting reverse, store this in head 
    // printLL(head);
    // cout<<endl;
    
    return 0;
}