#include <iostream>
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
    if(head -> left == NULL){
        insertNode(head->left, data);
    }
    if(head -> left != NULL){
        insertNode(head->right, data);
    }
}

bool DFS(TreeNode* root, int x, int y, int count, int &valX, int &valY){
    if(root == NULL) return false;
    if(root -> val == x){
        valX = count;
        return true;
    }
    if(root -> val == y){
        valY = count;
        return true;
    }
    count++;
    if(DFS(root -> left, x, y, count, valX, valY) and DFS(root -> right, x, y, count, valX, valY)){
        return false;
    }
    
    if(DFS(root -> left, x, y, count, valX, valY) or DFS(root -> right, x, y, count, valX, valY)){
        if(valX == valY) return true;
    }
    return false;
}

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int valX = 0;
        int valY = 0;
        DFS(root, x, y, 0, valX, valY);
        cout << valX << " " << valY;
        return valX == valY;
    }
};

int main(void){
    Node* root;
    root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 0);
    insertNode(root, 5);

    
    Solution obj;
    obj.binaryTreePaths(root);

}