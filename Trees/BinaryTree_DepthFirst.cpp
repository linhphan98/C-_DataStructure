#include <iostream>
using namespace std;

struct BstNode{
	char data;
	BstNode* left;
	BstNode* right;
};

void Preorder(BstNode* root){
	if(root == NULL) return;
	cout << root -> data << " ";
	Preorder(root -> left);
	Preorder(root -> right); 
};

// If the tree is the binary search tree, this function will return a sorted list
void Inorder(BstNode* root){
	if(root == NULL) return;
	Inorder(root -> left);
	cout << root -> data << " ";
	Inorder(root -> right);
};

void Postorder(BstNode* root){
	if(root == NULL) return;
	Postorder(root -> left);
	Postorder(root -> right);
	cout << root -> data << " ";
};

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

	cout << "Preorder:" << endl;
	Preorder(rootPtr);
	cout << endl;
	cout << "Inorder:" << endl;
	Inorder(rootPtr);
	cout << endl;
	cout << "Postorder:" << endl;
	Postorder(rootPtr);
	
	return 0;
}