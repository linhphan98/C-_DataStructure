#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            int count = 1;
            while(nums[i] < nums[i - count]){
                if(i - count >= 0){
                    count++;
                }
                if(count > i){
                    break;
                }
            }
            count--;
            int temp = nums[i];
            nums.erase(nums.begin() + i);
            nums.insert(nums.begin() + i - count, temp);
        }
    }
};

int main(void){
    vector<int> nums;
    Solution obj; 
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);

    obj.sortColors(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}