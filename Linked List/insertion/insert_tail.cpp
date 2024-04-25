#include<iostream>
using namespace std;

class Node{
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

void insertAtTail(Node* &head, Node* &tail, int data){

    if(tail == NULL){ // if empty LL
        // creat new node
        Node* newNode = new Node(data);

        // update head & tail
        head = tail = newNode;
    }
    else{
        // creat new node
        Node* newNode = new Node(data);

        //attatch tail node to new node 
        tail -> next = newNode;

        //update tail
        tail = newNode;
    }
}

void printLL(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp -> data << " ->";
        temp = temp -> next;
    }
}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(13);
    Node* fourth = new Node(15);

    first -> next = second;
    second -> next = third;
    third -> next = fourth;

    Node* head = first;
    Node* tail = fourth;

    printLL(head);
    cout<<endl;
    insertAtTail(head, tail, 500);
    printLL(head);

}