// BST is a binary tree in which for each node, value of all the nodes in the left
// subtree is lesser or equal and value of all the nodes in the right subtree is greater
// maximum of two child for each node and each of that child should also be a BST

#include <iostream>
#include <limits>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

bool IsBinarySearchTree(Node* root, int minValue, int maxValue){
	if(root == NULL) return true;
	if(root -> data > minValue
	&& root -> data < maxValue
	&& IsBinarySearchTree(root -> left, minValue, root->data)
	&& IsBinarySearchTree(root -> right, root -> data, maxValue))
		return true;
	else 
		return false;
}

Node* getNewNode(int data){
	Node* newNode = new Node();
	newNode -> data = data;
	newNode -> right = NULL;
	newNode -> left = NULL;
	return newNode;
};
void insert(Node** root, int data){
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
	Node* rootPtr = NULL; 
	insert(&rootPtr,15);
	insert(&rootPtr,10);
	insert(&rootPtr,20);
	insert(&rootPtr,25);
	insert(&rootPtr,12);
	insert(&rootPtr,8);

	bool answer = IsBinarySearchTree(rootPtr, INT_MIN, INT_MAX);
	if(answer) cout << "Binary Search Tree" << endl;
	return 0;
}