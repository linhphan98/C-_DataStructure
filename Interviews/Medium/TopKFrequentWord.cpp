// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> table;
        map<int, vector<string>, greater<int> > order;
        vector<string> answer;
        for(int i = 0; i < words.size(); i++){
            table[words[i]]++;
        }
        for(auto x : table){
            if(order[x.second].size() != 0){
                for(int i = 0; i < order[x.second].size(); i++){
                    if(x.first[0] - '0' > order[x.second][i][0] - '0'){
                        order[x.second].push_back(x.first);
                        break;
                    }
                    if(x.first[0] - '0' == order[x.second][i][0] - '0'){
                        if(x.first.length() > order[x.second][i].length()){
                            order[x.second].push_back(x.first);
                        }
                    }
                }
            }else{
                order[x.second].push_back(x.first);
            }
        }
        for(auto x : order){
            for(int i = 0; i<x.second.size();i++){
                answer.push_back(x.second[i]);
                k--;
                if(k==0) return answer;
            }
        }
        return answer;
    }
};