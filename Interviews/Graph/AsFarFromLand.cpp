// Input: [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: 
// The cell (1, 1) is as far as possible from all the land with distance 2.

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.size() < 1 or grid.size() > 100) return -1;
        vector<vector<int>> waters;
        vector<vector<int>> lands;
        int answer = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int x = 0; x < grid[i].size(); x++){
                if(grid[i][x] == 0){
                    waters.push_back({i,x});
                }else{
                    lands.push_back({i,x});   
                }
            }
        }
        if(waters.size() == 0 or lands.size() == 0) return -1;
        for(int i = 0; i < waters.size(); i++){
            int smallest = 100;
            for(int x = 0; x < lands.size(); x++){
                int temp = 0;
                temp = abs(waters[i][0] - lands[x][0]) + abs(waters[i][1] - lands[x][1]);
                if(smallest > temp) smallest = temp;
            }
            if(answer < smallest) answer = smallest;
        }
        return answer;   
    }
};