#include <iostream>
#include <list>
#include <math.h>
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

int getDecimalValue(Node* head){
    list<int> stack;
    while(head != NULL){
        stack.push_back(head -> data);
        head = head -> next;
    }

    int sum = 0;
    int level = 0;
    while(!stack.empty()){
        if(stack.back() == 0){
            sum += 0;         
        }
        if(stack.back() == 1){
            sum += pow(2,level);
        }
        stack.pop_back();
        level++;
    }
    return sum;
}

int main(void){
    Node* head;
    head = NULL;
    
    insertNode(head, 0);
    insertNode(head, 0);
    insertNode(head, 1);

    int answer = getDecimalValue(head);
    cout << answer << endl;
    return 0;
}


