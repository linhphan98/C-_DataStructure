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
void BFS(TreeNode* root, vector<TreeNode*> &list){
    if(root == NULL) return;
    list.push_back(root);
    if(root -> left != NULL) BFS(root -> left, list);
    if(root -> right != NULL) BFS(root -> right, list);
}
vector<TreeNode*> BFS(TreeNode* root, int x){
    vector<TreeNode*> list;
    vector<TreeNode*> answer;
    list.push_back(root);
    bool keep = false;
    while(!list.empty()){
        TreeNode* front = list.front();
        if(front -> val == x) {
            keep = true;
            break;
        }
        list.erase(list.begin());
        if(front -> left != NULL) list.push_back(front->left);
        if(front -> right != NULL) list.push_back(front -> right);
    }
    if(keep){
        BFS(list.front(), answer);
    }
    return answer;
}
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(root == NULL) return true;
        vector<TreeNode*> list;
        list = BFS(root, x);
        if(list.size() >= n/2.0) return false;
        return true;
    }
};