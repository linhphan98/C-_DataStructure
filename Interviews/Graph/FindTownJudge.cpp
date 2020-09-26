// Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
// Output: 3

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N < 1 or N > 1000) return -1;
        if(trust.size() < 0 or trust.size() > 10000) return -1;
        if(trust.size() == 0 and N == 1) return 1;
        if(trust.size() == 0 and N != 1) return -1;
        map<int, vector<int>> table;
        vector<int> answer;
        int ans = 0;
        int count = 0;
        
        for(int i = 0; i < trust.size(); i++){
            if(trust[i][0] == trust[i][1]) return -1;
            if(trust[i].size() != 2) return -1;
            if((trust[i][0] < 1 or trust[i][0] > N) and
            (trust[i][1] < 1 or trust[i][0] > N)) return -1;
            table[trust[i][0]].push_back(trust[i][1]);
        }
        for(auto x : table){
            for(int i = 0; i < x.second.size(); i++){
                if(table[x.second[i]].size() == 0) {
                    vector<int>::iterator it;
                    it = find(answer.begin(), answer.end(), x.first);
                    if(it == answer.end()) {
                        answer.push_back(x.first);
                        ans = x.second[i];
                    }
                }
            }
        }
        if(answer.size() == N - 1) return ans;
        return -1;
    }
};