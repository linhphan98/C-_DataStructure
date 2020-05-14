#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next; 
	Node* prev;
};

Node* head;

Node* getNewNode(int x){
	// if we do not use pointer, the var will be deleted after the function is completed
	Node *newNode = new Node();
	newNode -> data = x;
	newNode -> prev = NULL;
	newNode -> next = NULL;
	return newNode;
};

void insertBeginning(int x){
	Node* newNode = getNewNode(x);
	if(head == NULL){
		head = newNode;
		return;
	}
	newNode -> next = head;
	head -> prev = newNode; 
	head = newNode;
};

void insertLast(int x){
	Node *newNode = getNewNode(x);
	Node *temp = head;

	if(head == NULL){
		head = newNode;
		return;
	};
	while(temp -> next != NULL){
		temp = temp -> next;
	};
	newNode -> prev = temp;
	temp -> next = newNode;
	newNode -> next = NULL;
};

void print(){
	Node *temp = head;
	while(temp != NULL){
		cout << temp -> data << endl;
		temp = temp -> next;
	}
};

void reversePrint(){
	Node *temp = head;
	while(temp -> next != NULL){
		temp = temp->next;
	};

	while(temp != NULL){
		cout << temp -> data << endl;
		temp = temp -> prev; 
	}
};

int main(void){
	head = NULL;
	for (int i = 0; i < 5; i++){
		insertBeginning(i);
	}
	insertLast(12);
	print();
	cout << "Reverse" << endl;
	reversePrint();
	return 0; 
}





