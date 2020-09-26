// [1,2,2,3,4,4,3]
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
bool DFS(TreeNode* left, TreeNode* right){
    if(left == NULL and right == NULL) return true;
    if(left == NULL and right != NULL) return false;
    if(left != NULL and right == NULL) return false;
    if((left -> val == right -> val) and DFS(left -> left, right -> right) and DFS(left -> right, right -> left)) return true;
    return false;
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if(root -> left == NULL and root -> right == NULL) return true;
        return DFS(root->left, root->right);
    }
};