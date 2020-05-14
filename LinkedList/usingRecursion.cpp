#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
};

struct Node* head; 

void insert(int num){
	Node* temp = new Node();
	temp -> data = num;
	temp -> next = head; 
	head = temp;
};

void print(Node* p){
	if(p == NULL) return;
	cout << p -> data << endl;
	print(p->next);
	// putting line 22 before line 21 will make the function become a 
	// reverse print function because of the execution stack when cout not called 
	// and the recursion was called before the cout get executed
};

void reverseList(Node* p){
	if(p -> next == NULL){
		head = p;
		return;
	}
	reverseList(p -> next);
	Node* q = p->next;
	q -> next = p;
	p->next = NULL;
	// draw 4 boxes of 2|100 4|200 5|150 4|250 and implement each line with a recursion
}

int main(void){
	for(int i = 0; i < 5; i++){
		insert(i);
	};

	reverseList(head);
	print(head);
	return 0; 
}