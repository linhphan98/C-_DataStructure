// We need to check the Horizontal Distances from the root for all nodes. If two nodes have the same Horizontal Distance (HD), then they are on the same vertical line. 
// The idea of HD is simple. HD for root is 0, a right edge (edge connecting to right subtree) is considered as +1 horizontal distance
// and a left edge is considered as -1 horizontal distance. For example, in the above tree, 
// HD for Node 1 is at -2, HD for Node 2 is -1, HD for 5 and 6, 2 and 3 is 0 and HD for node 7 is +2.
// We can do an in-order traversal of the given Binary Tree. While traversing the tree, we can recursively calculate HDs. We initially pass the horizontal distance as 0 for root. 
// For left subtree, we pass the Horizontal Distance as Horizontal distance of root minus 1. For right subtree, we pass the Horizontal Distance as Horizontal Distance of root plus 1.

//    	 4
//     /   \
//   2      6
//  / \    / \
// 1   3  5   7

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node{
	int data; 
	Node* left;
	Node* right;
};

Node* getNewNode(int data){
	Node* newNode = new Node();
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode; 
}

void insert(Node** root, int data){
	if(*root == NULL){
		*root = getNewNode(data); 
		return;
	}
	if(data <= (*root) -> data){
		insert(&((*root) -> left), data); 
	}else{
		insert(&((*root) -> right), data); 
	}
}

void inorderSearch(unordered_map<int, vector<int> > &m, Node** root, int HorDistance){
	if(*root == NULL){
		return;
	}
	(m[HorDistance]).push_back((*root) -> data);
	if((*root) -> left != NULL){
		inorderSearch(m, &((*root)->left), HorDistance-1);
	}
	if((*root) -> right != NULL){
		inorderSearch(m, &((*root)->right), HorDistance+1);
	}
}

int main(void){
	Node* rootPtr = NULL;
	unordered_map <int, vector<int> > m;

	insert(&rootPtr,4);
	insert(&rootPtr,2);
	insert(&rootPtr,6);
	insert(&rootPtr,1);
	insert(&rootPtr,3);
	insert(&rootPtr,5);
	insert(&rootPtr,7);

	inorderSearch(m, &rootPtr, 0);
	for(auto x : m){
		int sum = 0; 
		for(int i = 0; i < x.second.size(); i++){
			sum += x.second[i];
		}
		cout << sum << endl;
	}
}

