// for stack we only have two option of inserting and deleting a Node
// either at the beginning (head) which has a time complexity of O(1)
// or at the end of the list (tail) which has a time complexity of O(n) 
// every operation of stack has to be O(1) => beginning is the only choice

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* top = NULL;

void push(int x){
	Node* temp = new Node();
	temp -> data = x;
	temp -> next = top;
	top = temp;
};

void pop(){
	Node* temp;
	if(top == NULL) return;
	temp = top; 
	top = top -> next;
	delete (temp);
};

void print(){
	while(top != NULL){
		cout << top -> data << endl;
		top = top -> next;
	}
};

int main(void){
	for(int i = 0; i < 5; i++){
		push(i);
	}
	pop();
	print();
	return 0;
}