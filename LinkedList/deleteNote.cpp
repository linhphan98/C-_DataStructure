#include <iostream>
using namespace std;
 
struct Node{
	int data;
	Node* next;
};

struct Node* head; 

void insert(int x){
	Node* temp = new Node();
	Node* rep = head;
	temp -> data = x;
	temp -> next = NULL;
	if(head == NULL){
		head = temp;
		return;
	};
	while(rep -> next != NULL){
		rep = rep -> next;
	};
	rep->next = temp;
};

void print(){
	while(head != NULL){
		cout << head -> data << endl;
		head = head -> next;
	};
};

void deleteNode(int position){
	Node* temp1 = head;
	if(position == 1){
		head = temp1 -> next;
		delete temp1;
		return;
	};
	for(int i = 0; i < position-2; i++){
		temp1 = temp1 -> next;
	};

	// temp1 points to (position - 1)th Node
	Node* temp2 = temp1 -> next; // position(th) Node 
	temp1 -> next = temp2 -> next; // (position + 1)th Node
	delete temp2;
};

int main(void){
	head = NULL;
	for(int i = 0; i < 5; i++){
		insert(i);
	};
	deleteNode(2);
	print();
	return 0;
};