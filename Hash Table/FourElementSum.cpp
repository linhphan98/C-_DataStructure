// Input:   {3, 4, 7, 1, 2, 9, 8}
// Output:  (3, 8) and (4, 7)
// Explanation: 3+8 = 4+7

// Input:   {3, 4, 7, 1, 12, 9};
// Output:  (4, 12) and (7, 9)
// Explanation: 4+12 = 7+9

// Input:  {65, 30, 7, 90, 1, 9, 8};
// Output:  No pairs found

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main(void){
	int input[7] = {3, 4, 7, 1, 2, 9, 8};
	unordered_map <int, queue<int> > umap; 
	for(int i = 0; i < 7; i++){
		for(int x = i + 1; x <= 6; x++){
			if(umap[input[i] + input[x]].empty()){
				queue<int> q; 
				q.push(input[i]);
				q.push(input[x]);
				umap[input[i] + input[x]] = q;
			}else{
				umap[input[i] + input[x]].push(input[i]);
				umap[input[i] + input[x]].push(input[x]);
			}
		}
	}

	if(umap.empty()){
		cout << "No pairs found" << endl;
	}else{
		for(auto x : umap){
			if(x.second.size() >= 4){
				cout << x.first << " = ";
				while(!x.second.empty()){
					cout << x.second.front() << " + ";
					x.second.pop();
					cout << x.second.front() << " , ";
					x.second.pop();
				}
				cout << endl;
			}
		}
	}
	

	return 0;
}

