#include <iostream>
#include <list>
#include <vector>

using namespace std;

void addEdge(vector<int> adj[], int src, int dest){
	adj[src].push_back(dest);
};

void displayGraph(vector<int> adj[], int size){
	for(int i = 0; i < size; i++){
		cout << i << " --> ";
		for(int x = 0; x < adj[i].size(); x++){
			cout << adj[i][x] << " ";
		}
		cout << endl;
	}
}

void tranposeGraph(vector<int> adj[], vector<int> trans[], int size){
	for(int i = 0; i < size; i++){
		for(int x = 0; x < adj[i].size(); x++){
			addEdge(trans, adj[i][x], i);
		}
	}
}

int main(void){
	int size = 5;
	// array type var is pass by reference by default so we do not need to pass in the address
	// in the Mother Vertex example, it was not array type so we have to use address to change
	vector<int> adjacent[size];
	addEdge(adjacent, 0, 1); 
    addEdge(adjacent, 0, 4); 
    addEdge(adjacent, 0, 3); 
    addEdge(adjacent, 2, 0); 
    addEdge(adjacent, 3, 2); 
    addEdge(adjacent, 4, 1); 
    addEdge(adjacent, 4, 3); 

    vector<int> transpose[size]; 
    tranposeGraph(adjacent, transpose, size); 

    displayGraph(transpose, size); 
	return 0;
}