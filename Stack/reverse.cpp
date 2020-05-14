#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head;

void reverseString(char *C, int length){
	stack<char> S; 
	// loop for push
	for (int i = 0; i < length; i++){
		S.push(C[i]);
	};

	// loop for pop
	for(int i = 0; i < length; i++){
		C[i] = S.top(); // overwrite the character at index i
		S.pop();
	};
};

void reverseLinkedList(){
	if(head == NULL) return;
	stack<Node*> S;
	Node* temp = head;
	while(temp != NULL){
		S.push(temp);
		temp = temp -> next;
	}
	temp = S.top();
	head = temp;
	S.pop();
	while(!S.empty()){
		temp -> next = S.top();
		S.pop();
		temp = temp -> next;
	}
	temp -> next = NULL;
};

void print(){
	Node* temp = head;
	while(temp != NULL){
		cout << temp -> data << endl;
		temp = temp -> next;
	}
};

void push(int x){
	Node* temp = new Node();
	temp -> data = x;
	temp -> next = head;
	head = temp;
};

int main(void){
	char C[51];
	gets(C);
	reverseString(C, strlen(C));
	printf("%s \n",C);
	for(int i = 0; i < 5; i++){
		push(i);
	};
	print();
	cout << "reversed" << endl;
	reverseLinkedList();
	print();
}