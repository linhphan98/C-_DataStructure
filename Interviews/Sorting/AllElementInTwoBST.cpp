#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


Node* getNewNode(int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> right = NULL;
    newNode -> left = NULL;
    return newNode;
};
void insert(Node** root, int data){
    if(*root == NULL){
        *root = getNewNode(data);
        return;
    }else if (data <= (*root) -> data){
        insert(&((*root) -> left), data);
    }else {
        insert(&((*root) -> right), data);
    }
};

void inOrderSearch(map<int,int> &table, TreeNode* root){
    if(root == NULL) return;
    if(root -> left != NULL) inOrderSearch(table, root -> left);
    table[root -> val]++;
    if(root -> right != NULL) inOrderSearch(table, root -> right);
}
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> answer; 
        map<int,int> table;
        inOrderSearch(table, root1);
        inOrderSearch(table, root2);

        for(auto x : table){
            while(x.second != 0){
                answer.push_back(x.first);
                x.second--;
            }
        }
        return answer;
    }
};

int main(void){
    Node* root1 = NULL; 
    Node* root2 = NULL;

    insert(&root1,2);
    insert(&root1,1);
    insert(&root1,4);

    insert(&root2,1);
    insert(&root2,0);
    insert(&root2,3);

    Solution obj;
    vector<int> answer = obj.getAllElements(root1, root2);

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }   
    return 0;
}