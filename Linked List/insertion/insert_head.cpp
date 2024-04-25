// steps :-

// 1. creat a new node
// 2. point the new node to head (newNode -> next = head)
// 3. update head

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(){
        this -> next = NULL;
    }
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertNewNode(Node* &head, Node* &tail, int data){
    // corner case . LL could be empty
    if(head == NULL){
        // step 1 : creat new node
        Node* newNode = new Node(data);

        // step 2 : update head and tail
        head = tail = newNode;
    }
    else{
        // 1. creat a new node
        Node* newNode = new Node(data);

        // 2. point the new node to head (newNode -> next = head)
        newNode -> next = head;

        // 3. update head
        head = newNode;
    }

}

void printLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data << "->";
        temp = temp -> next;
    }
}

int main(){

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first -> next = second;
    second -> next = third;
    third -> next = fourth;

    Node* head = first;
    Node* tail = NULL;

    printLL(head);
    cout<<endl;
    insertNewNode(head, tail, 100);
    printLL(head);
}