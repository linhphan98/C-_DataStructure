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
class Solution {
public:
int ans=0;
    
int DFS(TreeNode* root){
    if(root == NULL) return 0;
    int left = DFS(root -> left);
    int right = DFS(root -> right);
    ans += abs(left + right + root -> val - 1);
    return left + right + root -> val - 1;
}
int distributeCoins(TreeNode* root) {
    int temp = DFS(root);
    return ans;
}
};

// Input: [3,0,0]
// Output: 2
// Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

// Input: [0,3,0]
// Output: 3
// Explanation: From the left child of the root, we move two coins to the root [taking two moves].  Then, we move one coin from the root of the tree to the right child.

// Input: [1,0,2]
// Output: 2

// Input: [1,0,0,null,3]
// Output: 4