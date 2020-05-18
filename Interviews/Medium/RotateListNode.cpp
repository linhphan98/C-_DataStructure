#include <iostream>
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

void rotateNode(Node* &head, int num){
    while(num != 0){
        Node* tail1 = head;
        Node* tail2 = head -> next;
        while(tail2 -> next != NULL){
            tail1 = tail1 -> next;
            tail2 = tail2 -> next;

        }
        tail2 -> next = head;
        tail1 -> next = NULL;
        head = tail2;
        num--;
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
    // Solution obj;
    Node* head = NULL;
    for(int i = 0; i < 3; i++){
        insertNode(head, i);
    }
    rotateNode(head, 4);
    print(head);
    return 0;
}