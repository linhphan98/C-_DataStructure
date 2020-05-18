#include <iostream>
#include <map>
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

void partition(Node* &head, int x){
    Node* temp1 = head;
    Node* temp2 = head;
    Node* last = temp2 -> next;

    while(last != NULL){
        if(last -> data < x){
            while((temp1 -> next) -> data <= x){
                temp1 = temp1 -> next;
            }
            if(last -> next == NULL){
                temp2 -> next = NULL;
                last -> next = temp1 -> next;
                temp1 -> next = last;
            }else{
                temp2 -> next = last -> next;
                last -> next = temp1 -> next;
                temp1 -> next = last;
                last = temp2 -> next;
            } 
        }
        temp2 = last;
        last = last -> next;   
    }
}

void print(Node* head){
    Node* last = head;
    while(last != NULL){
        cout << last -> data << " -> ";
        last = last -> next;
    }
    cout << "NULL" << endl;
}

int main(void){
    Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 4);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 5);
    insertNode(head, 2);

    partition(head, 3);
    print(head);
    return 0;
}