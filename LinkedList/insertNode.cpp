#include <iostream>

using namespace std; 

struct Node{
	int data;
	Node* next;	
};

struct Node* head;

void InsertBeginning(int x){
	Node* temp = new Node();
	temp -> data = x;
	temp -> next = head;
	head = temp;
};

void Print(){
	while(head != NULL){
		cout << head -> data << endl;
		head = head -> next;
	}
};

void insertRandom(int input, int position){
	Node* insert = new Node();
	insert -> data = input;
	insert -> next = NULL; 
	if(position == 1){
		insert -> next = head;
		head = insert;
		return;
	};

	Node* headTemp = head;
	for(int i = 0; i < position-2; i++){
		headTemp = headTemp -> next;
	};
	insert -> next = headTemp -> next;
	headTemp -> next = insert;
};

int main(void){
	
	head = NULL;
	
	for (int i = 0; i < 5; i++){
		InsertBeginning(i);
	};

	insertRandom(12,2);
	Print();
	return 0;
}