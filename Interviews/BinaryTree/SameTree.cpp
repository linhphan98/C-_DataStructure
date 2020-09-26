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
bool DFS(TreeNode* p, TreeNode* q){
    if(p == NULL and q == NULL) return true;
    if(p == NULL and q != NULL) return false;
    if(p != NULL and q == NULL) return false;
    
    if(p -> val == q -> val){
       if(DFS(p -> left, q -> left)){
            if(DFS(p -> right, q -> right)) return true;
        } 
    }
    
    return false;
    
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return DFS(p, q);
    }
};