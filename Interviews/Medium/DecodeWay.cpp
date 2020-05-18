#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int answer = 1;
        vector<char> arr;

        for(int i = 0; i < s.length(); i++){
            arr.push_back(s[i]);
        }

        for(int i = 0; i < arr.size() - 1; i++){
            int sum = (arr[i] - '0')*10 + (arr[i+1] - '0');
            if(sum <= 26){
                answer++;
            } 
        }
        return answer;
    }
};

int main(void){
    Solution obj;

    int answer = obj.numDecodings("226");
    cout << answer << endl;
    return 0;
}