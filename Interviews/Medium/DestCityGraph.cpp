#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string> >& paths) {
        map<vector<string>,int> table;
        int max = 0;
        string answer;

        for(int i = 0; i < paths.size(); i++){
            table[paths[i]] = 1;
        }
        for(auto i = table.begin(); i != table.end(); i++){
            for(auto x = table.begin(); x != table.end(); x++){
                if(i == x) continue;
                if(x -> first[1] == i -> first[0]){
                    vector<string> temp;
                    temp.push_back(x -> first[0]);
                    temp.push_back(i -> first[1]);
                    if( i-> second > x -> second) table[temp] = i -> second + 1;
                    else table[temp] = x -> second + 1;
                }
                if(x -> first[0] == i -> first[1]){
                    vector<string> temp;
                    temp.push_back(i -> first[0]);
                    temp.push_back(x -> first[1]);
                    if( i-> second > x -> second) table[temp] = i -> second + 1;
                    else table[temp] = x -> second + 1;
                }
            }
        }

        for(auto x = table.begin(); x != table.end(); x++){
            if(max <= x -> second){
                answer = x->first[1];
                max = x -> second;
            }
        }
        return answer;
    }
};

int main(void){
    vector<string> path; 
    vector<vector<string> > listOfPath;
    path.push_back("jMgaf WaWA");
    path.push_back("iinynVdmBz");
    listOfPath.push_back(path);
    path.clear();
    path.push_back("QCrEFBcAw");
    path.push_back("wRPRHznLWS");
    listOfPath.push_back(path);
    path.clear();
    path.push_back("iinynVdmBz");
    path.push_back("OoLjlLFzjz");
    listOfPath.push_back(path);
    path.clear();
    path.push_back("OoLjlLFzjz");
    path.push_back("QCrEFBcAw");
    listOfPath.push_back(path);
    path.clear();
    path.push_back("IhxjNbDeXk");
    path.push_back("jMgaf WaWA");
    listOfPath.push_back(path);
    path.clear();
    path.push_back("jmuAYy vgz");
    path.push_back("IhxjNbDeXk");
    listOfPath.push_back(path);
    path.clear();
    
    Solution obj;
    string dest = obj.destCity(listOfPath);
    cout << dest << endl;
    return 0; 
}