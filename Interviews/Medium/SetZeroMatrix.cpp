// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> temp;
        int colSize = matrix[0].size();
        int rowSize = matrix.size();
        
        for(int row = 0; row < matrix.size(); row++){
            pair<int,int> pos;
            pos.first = row;
            pos.second = 0;
            for(int col = 0; col < matrix[row].size(); col++){
                if(matrix[row][col]==0){
                    pos.second = col;
                    temp.push_back(pos);
                }
            }
        }
        for(int i = 0; i < temp.size(); i++){
            for(int x = 0; x < rowSize; x++){
                matrix[x][temp[i].second] = 0;
            }
            for(int y = 0; y < colSize; y++){
                matrix[temp[i].first][y] = 0;
            }
        }
    }
};