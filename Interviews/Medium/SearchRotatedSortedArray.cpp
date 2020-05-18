#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int answer = 0;
        int mid = nums.size() / 2;

        while(nums.size() != 1){
            if(abs(nums[mid+1] - target) < abs(nums[mid-1] - target)){
                answer += mid;
                nums.erase(nums.begin(), nums.begin() + mid);
                mid = nums.size()/2;
            }else if(nums[mid] == target){
                answer += mid;
                break;
            }else{
                nums.erase(nums.begin() + mid, nums.end());
                mid = nums.size()/2;
            }
        }

        if(answer != 0){
            return answer;
        }else{
            return -1;
        }
    }
};

int main(void){
    vector<int> arr; 
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);

    Solution obj;
    int answer = obj.search(arr, 3);
    cout << answer << endl;
    return 0;
}