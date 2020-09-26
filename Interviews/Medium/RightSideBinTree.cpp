#include <iostream>
#include <vector>
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
    if(head -> left == NULL){
        insertNode(head->left, data);
        return;
    }
    if(head -> left != NULL){
        insertNode(head->right, data);
        return;
    }
}

void DFS(Node* head, vector<int> &answer){
    if(head == NULL) return;
    answer.push_back(head->data);
    if(head->right != NULL) DFS(head->right, answer);
}

vector<int> rightSideView(Node* root){
    vector<int> answer; 
    DFS(root, answer);
    return answer;
}

int main(void){
    Node* root;
    root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 0);
    insertNode(root, 5);
    insertNode(root, 0);
    insertNode(root, 4);

    vector<int> answer = rightSideView(root);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
}