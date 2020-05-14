#include <iostream>
using namespace std;
#define size 10

unsigned int front = -1;
unsigned int tail = -1; 
int A[size];

bool IsEmpty(){
	if((front == -1) && (tail == -1)){
		return true;
	}else{
		return false;
	}
};

// using a circular manner array so we do not lose memory space after dequeue and reuse the delete space 
void Enqueue(int x){
	if(((tail + 1) % size) == front){
		cout << "No Space" << endl;
		return;
	}else if(IsEmpty()){
		// initialize both to first place
		front = tail = 0;
	}else{
		tail = (tail + 1) % size;
	}
	A[tail] = x;
};

void Dequeue(){
	if(IsEmpty()){
		cout << "Queue is empty" << endl;
		return;
	}else if(front == tail){
		front = tail = -1;
	}else{
		front = (front+1) % size;
	}
};

int Front(){
	return A[front];
};

void print(){
	cout << "Array: ";
	if(tail >= front) {
		for(int i = front; i <= tail; i++) {
			cout << A[i] << " ";
		}
		return;
	}
	int i = front;
	while(i < size) {
		cout << A[i] << " ";
		i++;
	}
	for(i = 0; i <= tail; i++) {
		cout << A[i] << " ";
	}
};

int main(void){
	for (int i = 0; i < size; i++){
		Enqueue(i);
	};
	Dequeue();
	Dequeue();
	Enqueue(11);
	Enqueue(12);
	print();
}
