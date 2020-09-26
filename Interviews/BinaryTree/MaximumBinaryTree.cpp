// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:

//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1

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
int findMax(vector<int> list, int max){
    int pos = 0;
    for(int i = 0; i < list.size(); i++){
        if(max < list[i]) {
            max = list[i]; pos = i;
        }
    }
    return pos;
}
vector<int> subArray(vector<int> list, int start, int end){
    vector<int> temp;
    temp.assign(list.begin() + start, list.begin() + end);
    return temp;
}
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int max = findMax(nums, 0);       
        TreeNode* root = new TreeNode(nums[max]);        
        vector<int> temp = subArray(nums, 0, max);
        root->left = constructMaximumBinaryTree(temp);
        temp.clear();
        temp = subArray(nums, max+1, nums.size());
        root->right = constructMaximumBinaryTree(temp);
        temp.clear();
        return root;
    }
};