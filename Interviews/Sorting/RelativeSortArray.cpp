#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> table;
        for(int i = 0; i < arr1.size(); i++){
            table[arr1[i]]++;
        }
        arr1.clear();
        for(int i = 0; i < arr2.size(); i++){
            while(table[arr2[i]] != 0){
                arr1.push_back(arr2[i]);
                table[arr2[i]]--;
            }
            table.erase(arr2[i]);
        }
        for(auto x : table){
            while(x.second != 0){
                arr1.push_back(x.first);
                x.second--;
            }
        }
        return arr1;
    }
};

int main(void){
    vector<int> arr1;
    vector<int> arr2;

    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(1);
    arr1.push_back(3);
    arr1.push_back(2);
    arr1.push_back(4);
    arr1.push_back(6);
    arr1.push_back(7);
    arr1.push_back(9);
    arr1.push_back(2);
    arr1.push_back(19);

    arr2.push_back(2);
    arr2.push_back(1);
    arr2.push_back(4);
    arr2.push_back(3);
    arr2.push_back(9);
    arr2.push_back(6);

    Solution obj;
    arr1 = obj.relativeSortArray(arr1, arr2);

    for(int i = 0; i < arr1.size(); i++){
        cout << arr1[i] << " ";
    }
    return 0;
}