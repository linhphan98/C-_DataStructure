#include <iostream>
#include <list>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void insertNode(Node* &head, int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }
    if(head -> left == NULL) {
        insertNode(head -> left, data); 
        return;
    }
    if(head -> left != NULL) {
        insertNode(head -> right, data); 
        return;
    }
}

bool check(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;

    return (root1 -> data == root2 -> data) 
        &&  (check(root1 -> left, root2 -> right)
        &&  (check(root1 -> right, root2 -> left))
        );
}

bool isSymmetric(Node* root){
    if(root == NULL) return true;
    return check(root -> left, root -> right);
}

int main(void){
    Node* root;
    root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 4);
    insertNode(root, 3);

    bool answer = isSymmetric(root);

    cout << answer << endl;
}