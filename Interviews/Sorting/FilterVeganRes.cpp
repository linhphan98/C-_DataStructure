#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int> >& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> answer;
        map<int,vector<vector<int> >, greater<int> > table;
        bool check = false;

        if(veganFriendly == 1) {
            check = true;
        }
        for(int i = 0; i < restaurants.size(); i++){
            if(check){
                if(restaurants[i][2] != 1) continue;
            }
            if(restaurants[i][3] <= maxPrice){
                if(restaurants[i][4] <= maxDistance){
                    if(!table[restaurants[i][1]].empty()){
                        int count = 0;
                        while(count < table[restaurants[i][1]].size()){
                            if(table[restaurants[i][1]][count][3] >= restaurants[i][3]) count++;
                        }
                        count--;
                        table[restaurants[i][1]].insert(table[restaurants[i][1]].begin() + count, restaurants[i]);
                    }else{
                        table[restaurants[i][1]].push_back(restaurants[i]);
                    }
                }
            }
            
        }
        for(auto x : table){
            for(int i = 0; i < x.second.size(); i++){
                answer.push_back(x.second[i][0]);
            }      
        }
        return answer; 
    }
};

int main(void){
    vector<vector<int> > restaurants;
    vector<int> temp; 
    temp.push_back(1);
    temp.push_back(4);
    temp.push_back(1);
    temp.push_back(40);
    temp.push_back(10);
    restaurants.push_back(temp);
    temp.clear();

    temp.push_back(2);
    temp.push_back(8);
    temp.push_back(0);
    temp.push_back(50);
    temp.push_back(50);
    restaurants.push_back(temp);
    temp.clear();

    temp.push_back(3);
    temp.push_back(8);
    temp.push_back(1);
    temp.push_back(30);
    temp.push_back(4);
    restaurants.push_back(temp);
    temp.clear();

    Solution obj;
    obj.filterRestaurants(restaurants, 50, 10);
    return 0;
}