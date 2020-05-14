#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* front = NULL;
Node* tail = NULL;


void Enqueue(int x){
	Node *temp = new Node();
	temp -> data = x;
	temp -> next = NULL;

	if(front == NULL && tail == NULL){
		front = tail = temp;
		return;
	}
	tail -> next = temp;
	tail = temp;
}

void Dequeue(){
	Node* temp = front;
	if(front == NULL) return;
	if(front == tail){
		front = tail = NULL;
	}else{
		front = front -> next;
	}
	delete(temp);
}

void print(){
	Node* temp = front;
	while(temp != NULL){
		cout << temp -> data << endl;
		temp = temp -> next;
	}
}

int main(void){
	for(int i = 0; i < 5; i++){
		Enqueue(i);
	}
	print();
	cout << "Dequeued" << endl; 
	Dequeue();
	Dequeue();
	print();
}