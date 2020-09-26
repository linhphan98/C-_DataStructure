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
void DFS(TreeNode* root){
    if(root == NULL) return;
    if(root->left!=NULL and root->right == NULL){
        root->right=root->left;
        root->left=NULL;
        DFS(root->right);
        return;
    }
    if(root->right!=NULL and root->left == NULL){
        root->left=root->right;
        root->right=NULL;
        DFS(root->left);
        return;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    DFS(root->left);
    DFS(root->right);
}
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        DFS(root);
        return root;
    }
};