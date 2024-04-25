#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (){
        this -> next = NULL;
    } 
    Node (int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void printLL(Node* head){
    // whenever we pass a LL to a function we won't use actual pointer. 
    // we will make a temp pointer inside the function for accessing.
    Node* temp = head;
    int countNodes = 0;

    while(temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next; // moving pointer to the next node
        countNodes++;
    }
    cout << endl << "Number of Nodes : " << countNodes <<endl;
}

int main(){
    // creation of node (dynamically)
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    //connecting nodes
    first -> next = second;
    second -> next = third;
    third -> next = fourth;

    //creat a new pointer for pointing head of the LL.
    Node* head = first;
    cout << "Printing Linked List : ";
    printLL(head);
}