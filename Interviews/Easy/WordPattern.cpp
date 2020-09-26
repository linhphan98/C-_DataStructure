// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true
// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> tokens;
        map<char, string> table;
        stringstream check(str);
        string temp;
        vector<string>::iterator it;
        
        while(getline(check, temp, ' ')){
            tokens.push_back(temp);
        }
        if(pattern.length() != tokens.size()) return false;
        for(int i = 0; i < pattern.length(); i++){
            if(pattern[i] != pattern[(i+1) % pattern.length()] and tokens[i] == tokens[(i+1) % pattern.length()]) return false;
            if(pattern[i] == pattern[(i+1) % pattern.length()] and tokens[i] != tokens[(i+1) % pattern.length()]) return false;
            if(table[pattern[i]].length() == 0) {
                table[pattern[i]] = tokens[i];
                continue;
            }
            if(table[pattern[i]] == tokens[i]) continue;
            else return false;
        }
        
        return true;
    }
};