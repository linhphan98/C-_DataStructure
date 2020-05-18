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

void BFS(Node* head){
    list<Node*> queue;
    queue.push_back(head);
    
    while(!queue.empty()){
        Node* front = queue.front();
        cout << front -> data << " ";
        queue.pop_front();
        if(front->left != NULL){
            queue.push_back(front -> left);
        }
        if(front->right != NULL){
            queue.push_back(front -> right);
        }
    }
}

bool isValidBST(Node* root, int min, int max) {
    if(root == NULL) return true;
    if(root -> data > min
    && root -> data < max
    && isValidBST(root->left, min, root->data)
    && isValidBST(root->right, root->data, max)) return true;

    return false;
}

int main(void){
    Node* root;
    root = NULL;

    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 3);
    insertNode(root, 6);
    BFS(root);
    if(isValidBST(root, INT_MIN, INT_MAX)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }

}