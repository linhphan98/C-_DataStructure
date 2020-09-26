// Input: [1,0,1,0,1,0,1]
// Output: 22
// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
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
void DFS(TreeNode* root, vector<vector<int>> &list, vector<int> temp){
    if(root == NULL) return;
    temp.push_back(root->val);
    
    if(root->left == NULL and root->right == NULL){
        list.push_back(temp);
    }
    if(root->left != NULL) DFS(root->left, list, temp);
    if(root->right != NULL) DFS(root->right, list, temp);
}
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        vector<vector<int>> list;
        DFS(root, list, {});
        int sum = 0;
        while(!list.empty()){
            int bit = 0;
            vector<int> temp = list.front();
            for(int i = temp.size()-1; i >= 0; i--){
                if(temp[i] == 1){
                    sum += pow(2, bit);
                }
                bit++;
            }
            list.erase(list.begin());
        }
        return sum;
    }
};