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

void DFS(TreeNode* root, int height, int &num){
    if(root == NULL) {
        if(num > height) return;
        num = height;
        return;
    }
    height++;
    DFS(root -> left, height, num);
    DFS(root -> right, height, num);
    
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = 0;
        int right = 0;
        DFS(root -> left, 0, left);
        DFS(root -> right, 0, right);
        if(left == 0 and right == 0) return true;
        return abs(left - right) <= 1 ? true : false;
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