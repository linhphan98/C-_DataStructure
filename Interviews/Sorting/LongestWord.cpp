#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<string> rep = d;
        int max = 0;
        string answer;
        for(int i = 0; i < d.size(); i++){
            int count = 0;
            for(int x = 0; x < s.length(); x++){
                if(d[i].find(s[x]) != -1) {
                    count++;
                    d[i].erase(d[i].begin() + d[i].find(s[x]));
                }
            }
            if(max < count) {
                max = count;
                answer = rep[i];
            }
        }

        return answer;
    }
};

int main(void){
    vector<string> d;
    d.push_back("ale");
    d.push_back("apple");
    d.push_back("monkey");
    d.push_back("plea");

    Solution obj;
    string answer = obj.findLongestWord("abpcplea", d);
    cout << answer << endl;
    return 0;
}
