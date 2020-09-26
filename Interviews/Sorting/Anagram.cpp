#include <iostream>
#include <string.h>
#include <map>
using namespace std; 

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> table;
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++){
            table[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++){
            if(table[t[i]] == 0){
                return false;
            }
            if(table[t[i]] != 0){
                table[t[i]]--;
            }
        }
        return true;
    }
};

int main(void){
    Solution obj;
    bool answer = obj.isAnagram("ab", "a");
    cout << answer << endl;
    return 0; 
}