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

void deleteDuplicate(Node* &head){
    map<int, int> table;
    Node* temp1 = head;
    Node* temp2 = temp1 -> next;
    Node* temp3 = temp2 -> next;
    table[temp1 -> data] = 1;

    while(temp3 != NULL){
        if(temp1 -> data == temp2 -> data){
            while(temp2 -> data == temp1 -> data){
                temp2 = temp2 -> next;
            }
            table[temp2 -> data] = 1;
            if(temp1 != head){
                temp1 -> next = temp2;
            }else{
                temp1 = temp2;
                head = temp1;
            }
            temp2 = temp1 -> next;
            temp3 = temp2 -> next;
        }else if(table[temp3 -> data] != 0){
            temp2 = temp3;
            while(temp3 -> data == temp2 -> data){
                temp3 = temp3 -> next;
            }
            table[temp3 -> data] = 1;
            temp1 -> next = temp3;
            temp2 = temp3;
            temp3 = temp3 -> next; 
        }else{
            table[temp3 -> data] = 1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3 -> next;
        }
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
    insertNode(head, 0);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    deleteDuplicate(head);
    print(head);
    return 0;
}