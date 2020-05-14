// Input : A[] = {2, 2, 3, 3} 
// Output : 2 1 3 4
// Explanation:
// To make it a permutation of 1 to 4, 1 and 4 are
// missing from the array. So replace 2, 3 with 
// 1 and 4.

// Input :  A[] = {1, 3, 2}
// Output : 1 3 2

// Input : A[] = {10, 1, 2}
// Output : 3 1 2

#include <iostream>
#include <unordered_map>
using namespace std;

int main(void){
	int A[] = {2,2,33};
	unordered_map<int, int> umap;
	for(int i : A){
		if(i <= 3){
			umap[i] = 1;
		}
	}
	for (int x = 1; x <= 3; x++){
		if(umap[x] == 0){
			umap[x] = 1;
		}
	}
	for(auto x : umap){
		cout << x.first << " " << x.second << endl;
	}
	return 0; 
}