#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int> > kClosest(vector<vector<int> >& points, int k) {
        if(k < 1 || k > points.size()) return points;
        if(points.size() < k || points.size() > 10000) return points;
        map <double, vector<vector<int> > > table;

        for(int i = 0; i < points.size(); i++){
            if(points[i][0] <= -10000 || points[i][0] >= 10000) continue;
            if(points[i][1] <= -10000 || points[i][1] >= 10000) continue;
            double distance = 0.0;
            distance = sqrt(pow(points[i][0], 2.0) + pow(points[i][1], 2.0));
            table[distance].push_back(points[i]);
        }
        points.clear();
        int count = 0;
        for(auto x : table){
            for(int i = 0; i < x.second.size(); i++){
                points.push_back(x.second[i]);
                count++; 
            }
            if(count == k) break;
        }
        return points;

    }
};

int main(void){
    vector<int> arr1;
    vector<vector<int> > points;

    arr1.push_back(1);
    arr1.push_back(3);
    points.push_back(arr1);
    arr1.clear();

    arr1.push_back(-2);
    arr1.push_back(2);
    points.push_back(arr1);
    arr1.clear();

    arr1.push_back(2);
    arr1.push_back(-2);
    points.push_back(arr1);
    arr1.clear();

    Solution obj;
    points = obj.kClosest(points, 2);


    return 0;
}