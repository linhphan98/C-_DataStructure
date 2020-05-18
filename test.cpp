#include <iostream>
#include <list>
#include <vector>
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
    if(head -> data > data) {
        insertNode(head -> left, data); 
        return;
    }
    if(head -> data < data) {
        insertNode(head -> right, data); 
        return;
    }
}

void swapTree(Node* &root1, Node* &root2){
    Node* temp = root1;
    root1 = root2;
    root2 = temp;
}

void invertTree(Node* &root){
    if(root == NULL) return;
    list<Node*> queue;
    queue.push_back(root);
    while(!queue.empty()){
        Node* front = queue.front();
        queue.pop_front();
        if(front -> left != NULL && front -> right != NULL){
            swapTree(front->left, front->right);
            queue.push_back(front->left);
            queue.push_back(front->right);
        }
    }
}

void print(Node* root){
    vector<Node*> queue;
    queue.push_back(root);
    while(!queue.empty()){
        Node* front = queue.front();
        queue.erase(queue.begin());
        cout << front -> data << " ";
        if(front -> left != NULL) queue.push_back(front -> left);
        if(front -> right != NULL) queue.push_back(front -> right);
    }
}

int main(void){
    Node* head = NULL;

    insertNode(head, 4);
    insertNode(head, 2);
    insertNode(head, 7);
    insertNode(head, 1); 
    insertNode(head, 3); 
    insertNode(head, 6); 
    insertNode(head, 9); 


    invertTree(head);
    print(head);
}