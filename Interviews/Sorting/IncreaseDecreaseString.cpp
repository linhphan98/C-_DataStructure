#include <iostream>
#include <map>
#include <string.h>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        int turn = 0;
        string answer;
        while(s.length() != 0){
            if(turn%2 == 0){
                map<char, int, less<char> > temp;
                for(int i = 0; i < s.size(); i++){
                    if(temp[s[i]] == 0) {
                        temp[s[i]] = 1;
                        s.erase(s.begin()+i);
                        i--;
                    }
                }
                for(auto& x : temp){
                    answer += x.first;
                }
            }else{
                map<char, int, greater<char> > temp;
                for(int i = 0; i < s.size(); i++){
                    if(temp[s[i]] == 0) {
                        temp[s[i]] = 1;
                        s.erase(s.begin()+i);
                        i--;
                    }
                }
                for(auto& x : temp){
                    answer += x.first;
                }
            }   
            turn++;
        }
        return answer;
    }
};

int main(void){
    Solution obj;
    string answer = obj.sortString("ggggggg");
    cout << answer;
    return 0;
}