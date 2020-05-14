// case 1: No child 
// Case 2: one child 
// case 3: two child => find min in right-subtree, copy the value in tagetted node
// then delete the duplication from the rigth-subtree.
#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
};

void Delete(Node** root, int data){
	if(*root == NULL) return; // tree is empty
	else if(data < (*root) -> data) Delete(&((*root) -> left), data);
	else if(data > (*root) -> data) Delete(&((*root) -> right), data);
	else{
		// No child
		if((*root) -> left == NULL && (*root) -> right == NULL){
			*root = NULL;
			delete *root;
		}
		// One child
		else if((*root) -> left == NULL){
			*root = (*root) -> right;
			// these two lines are making sure the memory got deleted 
			Node *temp = *root;
			delete temp;
		}else if((*root) -> right == NULL){
			Node *temp = *root;
			*root = (*root) -> left;
			delete temp;
		}

		// 2 children
		else{
			Node* temp = FindMin((*root) -> right);
			(*root) -> data = temp -> data;
			Delete(&((*root) -> right), temp -> data);
		}
	}
};

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

void BreadthFirst(Node* root){
	if(root == NULL) return; 
	queue<Node*> Q; 
	Q.push(root);
	while(!Q.empty()){
		Node* current = Q.front();
		cout << current -> data << " ";
		if(current -> left != NULL) Q.push(current -> left);
		if(current -> right != NULL) Q.push(current -> right);
		Q.pop(); 
	}
};

int main(void){

	Node* rootPtr = NULL;
	insert(&rootPtr,7);
	insert(&rootPtr,10);
	insert(&rootPtr,4);
	insert(&rootPtr,5); 
	insert(&rootPtr,2); 
	insert(&rootPtr,1);
	insert(&rootPtr,3); 
	insert(&rootPtr,6); 
	insert(&rootPtr,9);

	Delete(&rootPtr,7);

	BreadthFirst(rootPtr);
	return 0;
}


