// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(target == nums[0]) return 0;
        if(target == nums[nums.size()-1]) return nums.size()-1;
        if(nums.size() == 1 and nums[0] != target) {
            return -1;
        }
        if(target < nums[0]){
            int start = nums.size() - 1;
            int count = 0;
            while(nums[start]!=target){
                count++;
                start--;
                if(count >= nums.size()) return -1;
            }
            return start;
        }
        if(target > nums[0]){
            int start = 1;
            int count = 1;
            while(nums[start]!=target){
                start++;
                count++;
                if(count >= nums.size()) return -1;
            }
            return start;
        }
    return -1;
    }  
};