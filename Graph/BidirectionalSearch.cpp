#include <iostream>
#include <list>
#include <vector>
using namespace std;

// not very good because we used too much space for array topParent and tailParent
class Graph{
private:
	int size; 
	list<int> *adj;
public:
	Graph(int size){
		this -> size = size;
		adj = new list<int>[size];
	}

	void addEdge(int src, int dest){
		this -> adj[src].push_back(dest);
		this -> adj[dest].push_back(src);
	}

	void BFS(list<int> &queue, bool *visited, int *parent){
		int current = queue.front();
		queue.pop_front();
		list<int>::iterator i;
		for(i = adj[current].begin(); i!= adj[current].end(); i++){
			if(!visited[*i]){
				parent[*i] = current;
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	int isIntersecting(bool *topVisited, bool *tailVisited){
		for(int i = 0; i < size; i++){
			if(topVisited[i] && tailVisited[i]){
				return i;
			}
		}
		return -1;
	}

	void printPath(int *topParent, int *tailParent, int top, int tail, int intersectNode){
		vector<int> path;
		path.push_back(intersectNode);
		int i = intersectNode;
		while(i != top){
			path.push_back(topParent[i]);
			i = topParent[i];
		}
		reverse(path.begin(), path.end());
		i = intersectNode;
		while(i != tail){
			path.push_back(tailParent[i]);
			i = tailParent[i];
		}

		vector<int>::iterator it;
		cout<<"*****Path*****\n"; 
	    for(it = path.begin();it != path.end();it++) 
	        cout<<*it<<" "; 
	    cout<<"\n"; 
	}

	int biDirSearch(int top, int tail){
		bool topVisited[size], tailVisited[size];
		int topParent[size], tailParent[size];
		list<int> topQueue, tailQueue;

		int intersectNode = -1;

		// initialize ot false 
		for(int i = 0; i < size; i++){
			topVisited[i] = false;
			tailVisited[i] = false;
		}

		topQueue.push_back(top);
		topVisited[top] = true;

		tailQueue.push_back(tail);
		tailVisited[tail] = true;

		topParent[top] = -1;
		tailParent[tail] = -1;

		while(!topQueue.empty() && !tailQueue.empty()){
			BFS(topQueue, topVisited, topParent);
			BFS(tailQueue, tailVisited, tailParent);

			intersectNode = isIntersecting(topVisited, tailVisited);
			if(intersectNode != -1){
				cout << "Path exist between " << top << " and " << tail << "\n"; 
	            cout << "Intersection at: " << intersectNode << "\n"; 
	  
	            // print the path and exit the program 
	            printPath(topParent, tailParent, top, tail, intersectNode); 

	            exit(0);
			}
		}
		return -1;
	}
};

int main(void)
{ 
    // no of vertices in graph 
    int n=15; 
  
    // source vertex 
    int s=0; 
  
    // target vertex 
    int t=14; 
  
    // create a graph given in above diagram 
    Graph g(n); 
    g.addEdge(0, 4); 
    g.addEdge(1, 4); 
    g.addEdge(2, 5); 
    g.addEdge(3, 5); 
    g.addEdge(4, 6); 
    g.addEdge(5, 6); 
    g.addEdge(6, 7); 
    g.addEdge(7, 8); 
    g.addEdge(8, 9); 
    g.addEdge(8, 10); 
    g.addEdge(9, 11); 
    g.addEdge(9, 12); 
    g.addEdge(10, 13); 
    g.addEdge(10, 14); 
    if (g.biDirSearch(s, t) == -1) 
        cout << "Path don't exist between "
             << s << " and " << t << "\n"; 
  
    return 0; 
} 