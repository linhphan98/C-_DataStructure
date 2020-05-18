#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int>ans;
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;
        int n = 0, m = 0;

        while(n <= row and m <= col){
            for(int i = m; i <= col; i++){
                ans.push_back(matrix[n][i]);
            }
            n++;
            for(int i = n; i <= row; i++){
                ans.push_back(matrix[i][col]);
            }
            col--;

            if(n <= row){
                for(int i = col; i >= m; i--){
                    ans.push_back(matrix[row][i]);
                }
                row--;
            }
            if(m <= col){
                for(int i = row; i >= n; i--){
                    ans.push_back(matrix[i][m]);
                }
                m++;
            }
        }
  
    return ans;
    }
};

int main(void){

    vector<vector<int> > matrix; 
    for(int i = 0; i < 3; i++){
        vector<int> temp;
        switch(i){
            case 0:
                temp.push_back(1);
                temp.push_back(2);
                temp.push_back(3);
                temp.push_back(4);
                matrix.push_back(temp);
            break;
            case 1:
                temp.push_back(5);
                temp.push_back(6);
                temp.push_back(7);
                temp.push_back(8);
                matrix.push_back(temp);
            break;
            case 2:
                temp.push_back(9);
                temp.push_back(10);
                temp.push_back(11);
                temp.push_back(12);
                matrix.push_back(temp);
            break;
        }
    }

    Solution obj; 
    vector<int> ans = obj.spiralOrder(matrix);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}