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

int findTilt(Node* root, int sum){
    if(root == NULL) {
        return sum;
    }

    int left = 0;
    int right = 0;
    if(root -> left != NULL){
        left = findTilt(root -> left, (root -> left) -> data);
    }
    if(root -> right != NULL){
        right = findTilt(root -> right, (root -> right) -> data);
    }
    sum += abs(left - right);
    return sum;
}

int main(void){
    Node* root;
    root = NULL;

    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 3);


    int answer = findTilt(root, 0);

    cout << answer << endl;
}