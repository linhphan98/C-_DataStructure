#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
};

struct Node* head; 

void print(Node *node){
	while(node != NULL){
		cout << node -> data << endl;
		node = node -> next;
	}
};

void insert(int num){
	Node* temp = new Node();
	temp -> data = num;
	temp -> next = head; 
	head = temp;
};

Node* reverse(){
	Node *current, *prev, *next; 
	current = head;
	prev = NULL;
	while(current != NULL){
		next = current -> next;
		current -> next = prev;
		prev = current; 
		current = next;
	};
	head = prev;
	return head;
};


int main(void){
	for(int i = 0; i < 5; i++){
		insert(i*2);
	};
	Node *reverseNode = reverse();
	print(reverseNode);
	return 0; 
}