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

class Solution {
public:
    vector<vector<int>> result;
    void printTree(TreeNode *root, int level){
        if(root==NULL){
            return;
        }
        
        //create a new list if we ran out of level
        if(result.size()==level){
            vector<int> i;
            result.push_back(i);
        }
        result[level].push_back(root->val);
        printTree(root->left, level+1);
        printTree(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        printTree(root, 0);
        return result;
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
    print(root, 1);
    
    // Solution obj;
    // obj.binaryTreePaths(root);

}