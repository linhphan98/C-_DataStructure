#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> answer;
        map<int, vector<int> > table;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0) {
                answer.push_back(0);
                continue;
            }
            int count = 7;
            int bits = 0;
            int num = arr[i];
            while(count != -1){
                if(pow(2,count) <= num){
                    bits++;
                    num -= pow(2,count);
                }
                if(num >= pow(2,count)){
                    continue;
                }else{
                    count--;
                }   
            }
            table[bits].push_back(arr[i]);

        }
        for(auto& x : table){
            sort(x.second.begin(), x.second.end());
            while(!x.second.empty()){
                answer.push_back(x.second.front());
                x.second.erase(x.second.begin());
            }
            
        }
        return answer;
    }
};

int main(void){
    Solution obj;
    vector<int> arr;
    for (int i = 0; i < 9; i++){
        arr.push_back(i);
    }
    vector<int> answer = obj.sortByBits(arr);
    for (int i = 0; i < 9; i++){
        cout << answer[i] << " ";
    }
    return 0;
}