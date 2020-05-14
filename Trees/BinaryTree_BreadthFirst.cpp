#include <iostream>
#include <queue>
using namespace std;

struct BstNode{
	char data;
	BstNode* left;
	BstNode* right;
};

void BreadthFirst(BstNode* root){
	if(root == NULL) return; 
	queue<BstNode*> Q; 
	Q.push(root);
	while(!Q.empty()){
		BstNode* current = Q.front();
		cout << current -> data << " ";
		if(current -> left != NULL) Q.push(current -> left);
		if(current -> right != NULL) Q.push(current -> right);
		Q.pop(); // removing the element at the front
	}
}
BstNode* getNewNode(char data){
	BstNode* newNode = new BstNode();
	newNode -> data = data;
	newNode -> right = NULL;
	newNode -> left = NULL;
	return newNode;
};

void insert(BstNode** root, char data){
	if(*root == NULL){
		*root = getNewNode(data);
		return;
	}else if (data <= (*root) -> data){
		insert(&((*root) -> left), data);
	}else {
		insert(&((*root) -> right), data);
	}
};

int main(void){
	/*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	BstNode* rootPtr = NULL;
	insert(&rootPtr,'M');
	insert(&rootPtr,'B');
	insert(&rootPtr,'Q');
	insert(&rootPtr,'Z'); 
	insert(&rootPtr,'A'); 
	insert(&rootPtr,'C');

	BreadthFirst(rootPtr);
	return 0;
}