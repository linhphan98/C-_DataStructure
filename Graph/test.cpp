#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int> >  fourSum(vector<int>& nums, int target) {
        vector<vector<int> > answer;
        map<vector<int> , int> table;
        for(int i = 0; i < nums.size(); i++){
            int size = nums.size();
            int x = i+1;
            while(nums[x%size] != nums[i]){
                int sum = nums[i];
                vector<int> temp;
                temp.push_back(nums[i]);
                for(int z = 1; z < 4; z++){
                    sum += nums[(x+z)%size];
                    temp.push_back(nums[(x+z)%size]);
                }
                if(sum == target){
                    table[temp] = sum;
                }
                x++;
            }
        }

        for(auto x : table){
            answer.push_back(x.first);
        }
        return answer;
    }
};

int main(void){
    vector<int> input;
    input.push_back(1);
    input.push_back(0);
    input.push_back(-1);
    input.push_back(0);
    input.push_back(-2);
    input.push_back(2);

    Solution obj;
    vector<vector<int> > answer = obj.fourSum(input, 3);
    for(int i = 0; i < answer.size(); i++){
        for(int x = 0; x < answer[i].size(); x++){
            cout << answer[i][x] << ", ";
        }
        cout << endl;
    }
    return 0;
}