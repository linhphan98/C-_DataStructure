#include <iostream>
#include <list>
#include <map>
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

bool DFS(int sum, TreeNode* head, int goal){
    if(head == NULL) return false;
    if(head -> left == NULL and head -> right == NULL and sum + head -> val == goal) return true;
    if(head -> left == NULL and head -> right == NULL and sum + head -> val != goal) return false;
    
    if(DFS(sum + head -> val, head -> left, goal) || DFS(sum + head -> val, head -> right, goal)) return true;
    return false;
    
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return DFS(0, root, sum);
    }
};

int main(void){
    Node* root;
    root = NULL;

    insertNode(root, 5);
    insertNode(root, 4);
    insertNode(root, 8);
    insertNode(root, 11);
    insertNode(root, 13);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 1);
    
    Solution obj;
    if(obj.hasPathSum(root, 25)) cout << "true";

}