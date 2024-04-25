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

int findLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
            Node* newNode = new Node(data);
            head = tail = newNode;
    }
    else{
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
            Node* newNode = new Node(data);
            head = tail = newNode;
    }
    else{
            Node* newNode = new Node(data);
            tail->next = newNode;
            tail = newNode;
    }
}

void insertAtAny(Node* &head, Node* &tail, int data, int position){
    
    int len = findLength(head);

    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }

    else if(position > len){
        insertAtTail(head, tail, data);
        return;
    }

    else{
            Node* newNode = new Node(data);

            Node* prev = NULL;
            Node* curr = head;

            while(position != 1){
                position--;
                prev = curr;
                curr = curr->next;
            }

            prev->next = newNode;
            newNode->next = curr;
    }
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
            cout << temp->data <<" ";
            temp = temp->next; 
    }
}

int main(){

    // here we are considering the range of length = (1 - len+1)
    Node* head = NULL;
    Node* tail = NULL;
        insertAtTail(head, tail, 20);
        insertAtTail(head, tail, 50);
        insertAtTail(head, tail, 60);
        insertAtTail(head, tail, 90);
        insertAtHead(head, tail, 77);

        printLL(head);
        cout<<endl;

        insertAtAny(head, tail, 500, 2);

        printLL(head);
        cout<<endl;

    return 0;
}