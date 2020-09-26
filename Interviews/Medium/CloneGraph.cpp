#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

map <Node*, Node*> m;
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        if(m.count(node) == 1) return m[node];
        Node* newNode = new Node(node -> val);
        m[node] = newNode;
        for(auto x : node -> neighbors){
            m[node] -> neighbors.push_back(cloneGraph(x));
        }
        return newNode;
    }
};


