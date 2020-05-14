#include <iostream>
#include <list>

using namespace std;
class Graph{
public:
	int numOfVertices;
	list<int> *adj;

	Graph(int v){
		this -> numOfVertices = v; 
		adj = new list<int>[v];
	}

	void addEdge(int src, int dest){
		adj[src].push_back(dest);
	}

	void BFS(int start){
		bool *visited = new bool[numOfVertices];
		for(int i = 0; i < numOfVertices; i++){
			visited[i] = false;
		}

		list<int> queue;

		visited[start] = true;
		queue.push_back(start);

		// iterator will be used to get all adjacent vertices of a vertex
		list<int>::iterator i;

		while(!queue.empty()){
			start = queue.front();
			queue.pop_front();
			cout << start << " ";
			for(i = adj[start].begin(); i != adj[start].end(); i++){
				if(!visited[*i]){
					visited[*i] = true;
					queue.push_back(*i);
				}
			}
		}
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
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
  
    return 0; 
} 