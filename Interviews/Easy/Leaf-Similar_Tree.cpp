#include <iostream>
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

void DFS(TreeNode* root, vector<int> &sequence){
    if(root == NULL) return;
    if(root -> left == NULL and root -> right == NULL){
        sequence.push_back(root->val);
        return;
    }
    DFS(root->left, sequence);
    DFS(root->right, sequence);
}
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        vector<int> seq2;
        DFS(root1, seq1);
        DFS(root2, seq2);
        if(seq1.size() != seq2.size()) return false;
        for(int i = 0; i < seq1.size(); i++){
            if(seq1[i] == seq2.front()){
                seq2.erase(seq2.begin());
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(void){
    Node* root;
    root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 4);
    insertNode(root, 3);

    bool answer = isSymmetric(root);

    cout << answer << endl;
}