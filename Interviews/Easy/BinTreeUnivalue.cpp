#include <iostream>
#include <math.h>
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

bool isUnivalTree(Node* root){
    if(root == NULL) return true;
    int unival = root -> data;
    list<Node*> queue;
    queue.push_back(root);
    while(!queue.empty()){
        Node* top = queue.front();
        queue.pop_front();
        if(top -> data != unival) return false;
        if(top->left != NULL) queue.push_back(top -> left);
        if(top->right != NULL) queue.push_back(top -> right);
    }
    return true;
}

int main(void){
    Node* root;
    root = NULL;

    insertNode(root, 2);
    insertNode(root, 2);
    insertNode(root, 2);
    insertNode(root, 2);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 2);


    bool answer = isUnivalTree(root);

    cout << answer << endl;
}