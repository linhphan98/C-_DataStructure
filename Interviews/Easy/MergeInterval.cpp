#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        for(int i = 0; i < intervals.size() - 1; i++){
            int x1 = intervals[i][0];
            int x2 = intervals[i][intervals[i].size() - 1];
            int y1 = intervals[i + 1][0];
            int y2 = intervals[i + 1][intervals[i + 1].size() - 1];

            if(x2 >= y1){
                vector<int> temp;
                temp.push_back(x1);
                temp.push_back(y2);
                intervals[i] = temp;
                intervals.erase(intervals.begin() + i + 1, intervals.begin() + i + 2);
                i--;
            }
        }
        return intervals;
    }
};

int main(void){
    vector<vector<int> > answer, input; 

    for(int i = 0; i < 4; i++){
        vector<int> temp;
        switch(i){
            case 0: 
                temp.push_back(1);
                temp.push_back(3);
                input.push_back(temp);
            break;
            case 1: 
                temp.push_back(2);
                temp.push_back(6);
                input.push_back(temp);
            break;
            case 2: 
                temp.push_back(8);
                temp.push_back(10);
                input.push_back(temp);
            break;
            case 3: 
                temp.push_back(15);
                temp.push_back(18);
                input.push_back(temp);
            break;
        }
    }

    Solution obj;
    answer = obj.merge(input);
    for(int i = 0; i < answer.size(); i++){
        for(int x = 0; x < answer[i].size(); x++){
            cout << answer[i][x] << " ";
        }
        cout << endl;
    }
    return 0;
}