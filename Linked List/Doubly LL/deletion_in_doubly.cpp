#include<iostream>
using namespace std;

class Node {

    public:

    int data;
    Node* prev;
    Node* next;

    Node(){
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
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

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<"->";
        temp = temp->next;
    }
}

void insertAtHead(Node* &head, Node* &tail, int data){
        if(head == NULL){
            Node* newNode = new Node(data);
            head = tail = newNode;
        }
        else{
            Node* newNode = new Node(data);
            head->prev = newNode;
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
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtAny(Node* &head, Node* &tail, int data, int position){

    if(head == NULL){
        Node* newNode = new Node(data);
        head = tail = NULL;
    }

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
// step 1 : creat a new node
        Node* newNode = new Node(data);
// step 2 : set prev and curr pointer
        Node* prevNode = NULL;
        Node* currNode = head;

        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
// step 3 : update pointers
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = currNode;
        currNode->prev = newNode;
    }
}

void deleteNode(Node* &head, Node* &tail, int position){

    if(head == NULL){
        // empty list
        cout<<"Can't delete as list is empty"<<endl;
        return;
    }

    if(head == tail){
        // single node
        Node* temp = head;
        delete temp;
        head = tail = NULL;
    }

int len = findLength(head);

    if(position == 1){
        // delete from head
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }

    else if(position == len){
        // delete from tail
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }

    else{
        // delete from middle

// step 1 : set prev/curr/next nodes
        Node* prevNode = NULL;
        Node* currNode = head;

        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        } // at the end of the loop we would get prevNode and currNode.

        Node* nextNode = currNode->next;

// step 2 : update pointers
        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;

        delete currNode;
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 80);

    printLL(head);
    cout<<endl;

    deleteNode(head, tail, 3);
    printLL(head);
}