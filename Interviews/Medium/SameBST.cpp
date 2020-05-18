#include <iostream>
#include <list>
#include <limits>
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
    if(data > head->data){
        insertNode(head->right, data);
    }
    if(data <= head->data){
        insertNode(head->left, data);
    }
}

list<int> DFSRecur(Node* root, list<int> value){
    if(root -> left != NULL) {
        value = DFSRecur(root -> left, value);
    }
    value.push_back(root -> data);
    if(root -> right != NULL){
        value = DFSRecur(root -> right, value);
    }
    return value;
}

list<int> DFS(Node* head){
    list<int> value;
    value = DFSRecur(head, value);
    return value;
}

bool sameTree(Node* root1, Node* root2){
    list<int> value1;
    list<int> value2;
    value1 = DFS(root1);
    value2 = DFS(root2);

    if(value1 == value2){
        return true;
    }
    return false;
}

int main(void){
    Node* root1;
    Node* root2;
    root1 = NULL;
    root2 = NULL;

    insertNode(root1, 1);
    insertNode(root1, 2);
    insertNode(root1, 3);
    insertNode(root2, 1);
    insertNode(root2, 2);
    insertNode(root2, 4);

    bool answer = sameTree(root1, root2);
    cout << answer << endl;
}