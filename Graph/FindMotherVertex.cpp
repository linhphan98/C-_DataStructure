#include <iostream>
#include <list>
#include <vector>

using namespace std;
class Graph{
private:
    int numOfvertices; 
    list<int> *adj; 

public:
    Graph(int v){
        numOfvertices = v;
        adj = new list<int>[v];
    }

    void addEdge(int src, int dest){
        adj[src].push_back(dest);
    }

    void DFSUtil(int v, vector<bool> &visited){
        visited[v] = true;
        list<int>::iterator i;

        for(i = adj[v].begin(); i != adj[v].end(); i++){
            if(!visited[*i]){
                DFSUtil(*i, visited);
            }
        }
    }

    int findMother(){
        vector<bool> visited(numOfvertices, false);

        // v: storing the one that has path to everyone
        int v = 0;

        for(int i = 0; i < numOfvertices; i++){
            if(visited[i] == false){
                DFSUtil(i, visited);
                v = i; 
            }
        }

        // this is to recheck if v is positively the right answer
        // reset all the values in visited[] as false and do DFS from v 
        fill(visited.begin(), visited.end(), false);
        DFSUtil(v, visited);
        for(int i = 0; i < numOfvertices; i++){
            if(visited[i] == false){
                return -1;
            }
        }
        return v;
    }
};

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
  
    cout << "A mother vertex is " << g.findMother(); 
  
    return 0; 
} 