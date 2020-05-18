#include <iostream>
#include <vector>
#include <math.h>
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

int widthOfBinaryTree(Node* root){
    int level = 0;
    int width = 0;
    int maxWidth = 0;
    vector<Node*> queue;
    queue.push_back(root);
    while(!queue.empty()){
        Node* front = queue.front();
        queue.erase(queue.begin());
        if(front -> data != -1) width++;
        if(width == pow(2,level)){
            width = 0;   
            maxWidth = pow(2,level);
            level++;
        }else if(maxWidth < width){
            maxWidth = pow(2,level);
        }
        if(front -> left != NULL) queue.push_back(front -> left);
        if(front -> right != NULL) queue.push_back(front -> right);
    }

    return maxWidth;
}


int main(void){
    Node* head = NULL;

    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 5); 


    int answer = widthOfBinaryTree(head);
    cout << answer << endl;

}