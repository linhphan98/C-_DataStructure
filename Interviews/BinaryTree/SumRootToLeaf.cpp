// Input: [4,9,0,5,1]
//     4
//    / \
//   9   0
//  / \
// 5   1
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.
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
void DFS(TreeNode* root, int num, vector<int> &path){
    if(root == NULL) return;
    num *= 10;
    num += root->val;
    if(root -> left == NULL and root -> right == NULL){
        path.push_back(num);
        return;
    }
    
    if(root -> left != NULL) DFS(root->left, num, path);
    if(root -> right != NULL) DFS(root->right, num, path);
}
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<int> path;
        DFS(root, 0, path);
        int sum = 0;
        while(!path.empty()){
            sum += path.front();
            path.erase(path.begin());
        }
        return sum;
    }
};