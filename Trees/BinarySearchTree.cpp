#include <iostream>
using namespace std;

struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* getNewNode(int data){
	BstNode* newNode = new BstNode();
	newNode -> data = data;
	newNode -> right = NULL;
	newNode -> left = NULL;
	return newNode;
};

// Height is the number of node from root to leaf: root -> left -> right -> leaf => height = 4
int findHeight(BstNode* root){
	if(root == NULL){
		return -1;
	}
	int leftHeight = findHeight(root -> left);
	int rightHeight = findHeight(root -> right);
	return max(leftHeight,rightHeight) + 1;
}

void insert(BstNode** root, int data){
	// because this root with one * is a local variable to the insert function 
	// we want the root in main function to be modified 
	// there is another way which is the same as linked list that we can make root as a global variable
	// so if root is not global we would need to use pointer to pointer in the case of linked list also
	if(*root == NULL){
		*root = getNewNode(data);
		return;
	}else if (data <= (*root) -> data){
		insert(&((*root) -> left), data);
	}else {
		insert(&((*root) -> right), data);
	}
};

bool search(BstNode** root, int data){
	if((*root) == NULL) return false;
	if((*root) -> data == data) return true;
	else if(data <= (*root) -> data) return search(&((*root) -> left), data);
	else return search(&((*root) -> right), data);
};

int findMinIterative(BstNode* root){
	if(root == NULL){
		cout << "Error: Tree is empty" << endl;
		return -1;
	}

	while(root-> left != NULL){
		root = root -> left;
	}
	return root -> data;
};

int findMaxIterative(BstNode* root){
	if(root == NULL){
		cout << "Error: Tree is empty" << endl;
		return -1;
	}

	while(root-> right != NULL){
		root = root -> right;
	}
	return root -> data;
};

int findMinRecursion(BstNode* root){
	if(root == NULL){
		cout << "Error: Tree is empty" << endl;
		return -1;
	}
	else if(root -> left == NULL){
		return root -> data;
	}
	return findMinRecursion(root->left);
};

int findMaxRecursion(BstNode* root){
	if(root == NULL){
		cout << "Error: Tree is empty" << endl;
		return -1;
	}
	else if(root -> right == NULL){
		return root -> data;
	}
	return findMinRecursion(root->right);
};

int main(void){
	BstNode* rootPtr = NULL; // pointer to root node
	// pass the address of the root in main into the function 
	// rootPtr is already a pointer so its address is pointer to a pointer 
	insert(&rootPtr,15);
	insert(&rootPtr,10);
	insert(&rootPtr,20);
	insert(&rootPtr,25);
	insert(&rootPtr,12);
	insert(&rootPtr,8);

	// int number = 0;
	// cout << "Enter a number to be searched" << endl;
	// cin >> number;
	// if(search(&rootPtr,number)) cout << "Found" << endl;
	// else cout << "Not Found" << endl;

	cout << "Finding min and max interatively" << endl;
	int minIte = findMinIterative(rootPtr);
	int maxIte = findMaxIterative(rootPtr);
	cout << "Min: " << minIte << " Max: " << maxIte << endl;

	cout << "Finding min and max recursively" << endl;
	int minRe = findMinRecursion(rootPtr);
	int maxRe = findMaxRecursion(rootPtr);
	cout << "Min: " << minRe << " Max: " << maxRe << endl;

	int height = findHeight(rootPtr);
	cout << "Height: " << height << endl;
	return 0;
}




