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

    ~Node(){
        cout<<"Destructor called for -> "<< this->data <<endl;
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

void deleteNode(Node* &head, Node* &tail, int position){

    if(head == NULL){
        // Empty LL
        cout<< "Can't delete in empty list"<<endl;
        return;
    }

    if(head == tail){
        // single element
        Node* temp = head;
        delete temp;
        head = tail = NULL;
        return;
    }    


    int len = findLength(head);

    if(position == 1){
            Node* temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;  
    }
    else if(position == len){
            Node* prev = head;

            while(prev->next != tail){
                prev = prev->next;
            }

            prev->next == NULL;
            delete tail;
    }
    else{
            Node* prev = NULL;
            Node* curr = head;

            while(position != 1){
                position--;
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
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

        //cout << tail->data <<endl;
        deleteNode(head, tail, 1);
        //cout << tail->data <<endl;

        printLL(head);
        cout<<endl;

    return 0;
}