#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        map<int, list<int> > table;
        for(int i = 0; i < height.size(); i++){
            table[height[i]].push_back(i);
        } 

        int maxHeight;
        list<int> heightPosition; // top 3 height position
        list<int> maxWidth; // top 3 width

        maxHeight = (table.rbegin() -> first);
        int maxPosition = *((table.rbegin() -> second).begin());

        for(int i = 0; i < 3; i++){
            if(table[maxHeight-i].size() != 0){
                while(table[maxHeight-i].size() != 0){
                    heightPosition.push_back(table[maxHeight-i].front());
                    table[maxHeight-i].pop_front();
                }
            }
            maxWidth.push_back(height.size() - (i+1));
        }

        int answer = 0;
        while(heightPosition.size() != 0){
            int num = height[heightPosition.front()] * (heightPosition.front() - maxPosition);
            heightPosition.pop_front();
            if(answer < num) answer = num;
        }

        while(maxWidth.size() != 0){
            int num = height[maxWidth.front()] * (maxWidth.front() - maxPosition);
            maxWidth.pop_front();
            if(answer < num) answer = num;
        }
        return answer;
    }
};

int main(void){
    Solution obj;
    vector<int> input; 
    input.push_back(1);
    input.push_back(8);
    input.push_back(6);
    input.push_back(2);
    input.push_back(5);
    input.push_back(4);
    input.push_back(8);
    input.push_back(3);
    input.push_back(7);

    int answer = obj.maxArea(input);
    cout << answer;
    return 0;
}