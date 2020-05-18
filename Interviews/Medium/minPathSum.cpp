#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int sumOne = 0;
        int sumTwo = 0;
        int row = 1;
        int col = 1;

        for(int i = 0; i < grid[0].size(); i++){
            sumOne += grid[0][i];
            sumTwo += grid[i][0];
        }
        for(int i = 1; i < grid.size(); i++){
            sumOne += grid[i][grid.size() - 1];
            sumTwo += grid[grid.size() - 1][i];
        }
        return (sumOne < sumTwo) ? sumOne : sumTwo;
    }
};

int main(void){
    vector<vector<int> > input; 

    for(int i = 0; i < 3; i++){
        vector<int> temp;
        switch(i){
            case 0: 
                temp.push_back(1);
                temp.push_back(3);
                temp.push_back(1);
                input.push_back(temp);
            break;
            case 1: 
                temp.push_back(1);
                temp.push_back(5);
                temp.push_back(1);
                input.push_back(temp);
            break;
            case 2: 
                temp.push_back(4);
                temp.push_back(2);
                temp.push_back(1);
                input.push_back(temp);
            break;
        }
    }

    Solution obj;
    int answer = obj.minPathSum(input);
    cout << answer << endl;
    return 0;
}