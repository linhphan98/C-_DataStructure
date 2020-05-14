#include <iostream>
using namespace std;
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void push(int x){
	if(top == MAX_SIZE - 1){
		cout << "Error: Stack Overflow" << endl;
		return;
	}
	A[++top] = x;
};

void pop(){
	if(top == -1){
		cout << "Error: there is no element to pop" << endl;
		return;
	}
	top--;
};

int Top(){
	return A[top];
};

void print(){
	for(int i = 0; i <= top; i++){
		cout << A[i] << endl;
	}
}


int main(void){
	for(int i = 0; i < 5; i++){
		push(i);
	}
	pop();
	print();
	push(12);
	print();
	return 0;
}