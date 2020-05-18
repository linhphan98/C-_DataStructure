#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int max_sum = INT_MIN;
        int current_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            current_sum += nums[i];
            if(max_sum < current_sum) max_sum = current_sum;
            if(current_sum < 0) current_sum = 0;
        }
    return max_sum; 
    }
};

int main(void){
    vector<int> input;
    input.push_back(-2);
    input.push_back(1);
    input.push_back(-3);
    input.push_back(4);
    input.push_back(-1);
    input.push_back(2);
    input.push_back(1);
    input.push_back(-5);
    input.push_back(4);

    Solution obj;
    int answer = obj.maxSubArray(input);
    cout << answer << endl;
    return 0;
}