// diag line to the right with left null
// input : [1,2,5,3,4,null,6]
// output: [1,null,2,null,3,null,4,null,5,null,6]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void DFS(TreeNode* root, vector<int> &list){
    if(root == NULL) return;
    list.push_back(root->val);
    if(root -> left != NULL) DFS(root -> left, list);
    if(root -> right != NULL) DFS(root -> right, list);
}

void insertBST(TreeNode* root, int data){
    if(root == NULL) {
        root = new TreeNode(data);
        return;
    }
    if(root -> left != NULL) root -> left = NULL;
    if(root -> right == NULL){
        root -> right = new TreeNode(data);
        return;
    }
    else insertBST(root -> right, data);
}
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        vector<int> list;
        DFS(root, list);
        root -> left = NULL;
        root -> right = NULL;
        for(int i = 1; i < list.size(); i++){
            insertBST(root, list[i]);
        }
    }
};