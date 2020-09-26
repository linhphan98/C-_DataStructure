#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> answer; 
    void DFS(int parent, int curr, vector<bool> visited, vector<vector<int> > graph){
        if(graph[parent].size() == 1 && graph[curr].size() == 0) {
            answer.push_back(parent);
            return;
        }
        visited[curr] = true;
        vector<int>::iterator it;
        for(it = graph[parent].begin(); it != graph[parent].end(); it++){
            if(!visited[*it]){
                DFS(parent, *it, visited, graph);
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int> >& graph) {
        vector<bool> visited(graph.size()-1, false); 
        for(int i = 0; i < graph.size(); i++){
            if(graph[i].size() == 0) {
                answer.push_back(i);
                continue;
            }
            DFS(i, i, visited, graph);
        }
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

    temp.push_back(2);
    temp.push_back(3);
    input.push_back(temp);
    temp.clear();

    temp.push_back(5);
    input.push_back(temp);
    temp.clear();

    temp.push_back(0);
    input.push_back(temp);
    temp.clear();

    temp.push_back(5);
    input.push_back(temp);
    temp.clear();

    input.push_back(temp);
    input.push_back(temp);

    Solution obj;
    vector<int> output = obj.eventualSafeNodes(input);
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    return 0;
}