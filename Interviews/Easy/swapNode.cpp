#include <iostream>
#include <exception>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertNode(Node* &head, int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* last = head;
    while(last -> next != NULL){
        last = last -> next;
    }
    last -> next = newNode;
}

void swapNode(Node* &head){
    Node* root = head;
    while(head != NULL && head -> next != NULL) {
        int temp = head -> data;
        head -> data = (head -> next) -> data;
        (head -> next) -> data = temp;
        head = (head -> next) -> next;
    }
    
    head = root;
}

void printNode(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

int main(void){
    Node* head;
    head = NULL;
    for(int i = 1; i < 7; i++){
        insertNode(head, i);
    }
    swapNode(head);
    printNode(head);
    return 0;
}


