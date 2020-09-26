// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0,
//  which makes it impossible to reach the last index.

bool DFS(vector<int> nums, int val){
    if(val >= nums.size()) return true;
    if(nums[val] == 0) return false;
    if(nums[nums.size()-1] == nums[val]) {
        return true;
    }
    if(DFS(nums, val + nums[val]) == false) {
        return false;
    }
    return true;
}
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        for(int i = 0; i < nums.size() - 1; i++){
            if(DFS(nums, i)) return true;
        }
        return false;
    }
};