#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int x = i + 1; x < nums.size(); x++){
                if(nums[i] < nums[x]){
                    int temp = nums[x];
                    nums[x] = nums[i+1];
                    nums[i+1] = temp;
                    i++;
                    break;
                }
            }
        }
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);  
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    Solution obj;
    obj.wiggleSort(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}