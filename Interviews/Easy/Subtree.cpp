// Given tree s:

//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// Given tree t:
//    4
//   / \
//  1   2
// Return false.

// Given tree s:

//      3
//     / \
//    4   5
//   / \
//  1   2
// Given tree t:
//    4 
//   / \
//  1   2

//  Return true;

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
bool DFS(TreeNode* s, TreeNode* t){
    if(s == NULL and t != NULL) return false;
    if(s != NULL and t == NULL) return false;
    if(s == NULL and t == NULL) return true;
    if(s -> val != t -> val) return false;
    if(DFS(s->left, t->left)) {
        if(DFS(s->right, t->right)){
            return true;
        }
    }
    return false;
}
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL) return false;
        if(isSubtree(s->left, t)){
            return true;
        }
        if(isSubtree(s->right, t)){
            return true;
        }
        if(s -> val == t -> val){
            return DFS(s, t);
        }
        return false;
    }
};