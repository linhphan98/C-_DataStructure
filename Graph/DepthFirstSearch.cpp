#include <iostream>
#include <list>
using namespace std;

class Graph{
private:
	int numOfVertices;
	list<int> *adjacent; 

public: 
	Graph(int v){
		this -> numOfVertices = v;
		adjacent = new list<int>[v];
	}

	void addEdge(int src, int des){
		adjacent[src].push_back(des);
	}

	void DFSUtil(int v, bool visited[]){
		visited[v] = true;
		cout << v << " ";
		list<int>::iterator i; 
		for(i = adjacent[v].begin(); i != adjacent[v].end(); i++){
			if(!visited[*i]){
				DFSUtil(*i, visited);
			}
		}
	}

	void DFS(int v){
		bool *visited = new bool[numOfVertices];
		for(int i = 0; i < numOfVertices; i++){
			visited[i] = false;
		}

		DFSUtil(v, visited);
	}
};

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 
  
    return 0; 
} 