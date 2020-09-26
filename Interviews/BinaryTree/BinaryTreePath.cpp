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

void DFS(vector<int> route, vector<vector<int> > &list, TreeNode* root){
    if(root -> left == NULL and root -> right == NULL){
        route.push_back(root -> val);
        list.push_back(route);
        return;
    }
    route.push_back(root -> val);
    if(root -> left != NULL){
        DFS(route, list, root -> left);
    }
    
    if(root -> right != NULL){
        DFS(route, list, root -> right);
    }
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int> > list;
        vector<int> route;
        vector<string> answer;
        DFS(route, list, root);
        for(int i = 0; i < list.size(); i++){
            string temp = "";
            for(int x = 0; x < list[i].size(); x++){
                temp += to_string(list[i][x]);
                temp += "->";
            }
            temp = temp.substr(0, temp.length()-2);
            answer.push_back(temp);
        }
        return answer;
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