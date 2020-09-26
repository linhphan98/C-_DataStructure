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
void DFS(TreeNode* root, int& depth, int count){
    if(root==NULL) return;
    if(root->left == NULL and root->right == NULL){
        if(depth<count) depth = count;
    }
    count++;
    if(root->left!=NULL) DFS(root->left, depth, count);
    if(root->right!=NULL) DFS(root->right, depth, count);
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        DFS(root, depth, 1);
        return depth;
    }
};