#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        map<int, int> table;
        int count = 0;

        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix[row].size(); col++){
                table[(10*col) + matrix[row].size() - count - 1] = matrix[row][col];
            }
            count++;
        }

        for(auto x : table){
            matrix[x.first/10][x.first%10] = x.second;
        }

        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix[row].size(); col++){
                cout << matrix[row][col] << " ";
            }
            cout << endl;
        }
    }
};

int main(void){

    vector<vector<int> > matrix; 
    for(int i = 0; i < 4; i++){
        vector<int> temp;
        switch(i){
            case 0:
                temp.push_back(5);
                temp.push_back(1);
                temp.push_back(9);
                temp.push_back(11);
                matrix.push_back(temp);
            break;
            case 1:
                temp.push_back(2);
                temp.push_back(4);
                temp.push_back(8);
                temp.push_back(10);
                matrix.push_back(temp);
            break;
            case 2:
                temp.push_back(13);
                temp.push_back(3);
                temp.push_back(6);
                temp.push_back(7);
                matrix.push_back(temp);
            break;
            case 3:
                temp.push_back(15);
                temp.push_back(14);
                temp.push_back(12);
                temp.push_back(16);
                matrix.push_back(temp);
            break;
        }
    }

    Solution obj; 
    obj.rotate(matrix);

    return 0;
}