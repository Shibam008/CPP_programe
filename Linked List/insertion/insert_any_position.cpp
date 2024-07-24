#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->next = NULL;
    }

    Node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int val) 
{
    if(head == NULL) 
    {
        Node *newNode = new Node(val);
        head = tail = newNode;
    }
    else
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int val)  
{
    if(head == NULL) 
    {
        Node* newNode = new Node(val);
        head = tail = newNode;
    }
    else
    {
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }
}

int getLen(Node* head) 
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL) 
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtAny(Node* &head, Node* &tail, int pos, int val) 
{
    int len = getLen(head);

    if(pos == 1) 
    {
        insertAtHead(head, tail, val);
        return;
    }
    else if(pos == len+1)
    {
        insertAtTail(head, tail, val);
        return;
    }
    else if(pos > len+1 || pos < 1) 
    {
        cout << "Invalid position!" << endl;
        exit(1);
    }
    else
    {
        Node* newNode = new Node(val);

        Node* prev = NULL;
        Node* curr = head;
        while(pos != 1) 
        {
            pos--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}

void display(Node* head)
{
    Node* temp = head;
    while(temp != NULL) 
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 15);
    insertAtHead(head, tail, 13);
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 18);
    insertAtHead(head, tail, 16);

    insertAtAny(head, tail, 5, 58);

    display(head);
}