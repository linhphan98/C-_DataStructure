#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
public:
    // vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph) {
    //     map<int,vector<int> > route;
    //     vector<int> headers;
    //     int src = 0;
    //     int dest = graph.size() - 1;

    //     for(int i = 0; i < graph.size(); i++){
    //         route[i] = graph[i];
    //         if(graph[i].size() == 0) continue;
    //         if(*(find(graph[i].begin(), graph[i].end(),dest))){
    //             headers.push_back(i);
    //         } 
    //     }
    //     graph.clear();

    //     for(int i = 0; i < headers.size(); i++){
    //         vector<int> path;
    //         for(auto x : route){
    //             if(*(find(x.second.begin(), x.second.end(),headers[i]))){
    //                 path.insert(path.begin(), headers[i]);
    //                 break;
    //             }   
    //         }
    //         if(path.size() != 0){
    //             path.push_back(dest);
    //             path.insert(path.begin(), src);
    //             graph.push_back(path);
    //         }
    //     }
    //     return graph;
    // }

    vector<vector<int> > answer; 
    vector<int> currPath;
    void dfs(int curr, int parent, vector<vector<int> >& graph){
        currPath.push_back(curr);
        if(curr == graph.size() - 1){
            answer.push_back(currPath);
        }
        for(int i = 0; i < graph[curr].size(); i++){
            dfs(graph[curr][i], curr, graph);
        }
        currPath.pop_back();
    }

    vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph) {
        dfs(0, -1, graph);
        return answer;
    }
};

int main(void){
    vector<int> temp;
    vector<vector<int> > input;

    temp.push_back(1);
    temp.push_back(2);
    input.push_back(temp);
    temp.clear();

    temp.push_back(3);
    input.push_back(temp);
    temp.clear();

    temp.push_back(3);
    input.push_back(temp);
    temp.clear();

    input.push_back(temp);

    Solution obj;
    vector<vector<int> > output = obj.allPathsSourceTarget(input);
    for(int i = 0; i < output.size(); i++){
        for(int x = 0; x < output[i].size(); x++){
            cout << output[i][x] << " ";
        }
        cout << endl;
    }
    return 0;
}