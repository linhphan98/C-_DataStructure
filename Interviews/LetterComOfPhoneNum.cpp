#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
private: 
    map<int, vector<char> > table; 
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
public:
    void inputIntoTable(){
        int count = 0;
        for(int i = 2; i <= 9; i++){
            if(i == 7 || i == 9){
                count = 4;
            }else{
                count = 3;
            }
            for(int x = 0; x < count; x++){
                table[i].push_back(alphabet[x]);
            }
            alphabet = alphabet.substr(count,alphabet.length());
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer; 
        string temp = "";
        
        vector<char> base = table[(digits[0] - '0')];
        for(int i = 1; i < digits.length(); i++){
            while(base.size() != 0){
                for(int x = 0; x < table[(digits[i]) - '0'].size(); x++){
                    string s1(1,base.front());
                    string s2(1,table[(digits[i] - '0')][x]);
                    temp += (s1+s2);
                    answer.push_back(temp);
                    temp = "";
                }
                base.erase(base.begin());
            }
        }
        return answer;
    }
};

int main(void){
    Solution obj; 
    obj.inputIntoTable();
    vector<string> answer = obj.letterCombinations("23");
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}