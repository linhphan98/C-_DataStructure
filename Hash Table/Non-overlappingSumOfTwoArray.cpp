// Input : A[] = {1, 5, 3, 8}
//         B[] = {5, 4, 6, 7}
// Output : 29
// 1 + 3 + 4 + 6 + 7 + 8 = 29

// Input : A[] = {1, 5, 3, 8}
//         B[] = {5, 1, 8, 3}
// Output : 0
// All elements are common.
#include <iostream>
#include <unordered_map> 
using namespace std;

int main(void){
	int A[] = {1, 5, 3, 8};
    int B[] = {5, 1, 8, 3};
    int sum = 0;
    unordered_map<int, int> umap;
    for(int i = 0; i < 4; i++){
    	umap[A[i]] = 1;
    }

    for(int i = 0; i < 4; i++){
    	try{
    		if(umap.at(B[i]) == 1){
    			umap.erase(B[i]);
    		}
    	}catch(exception e){
    		umap[B[i]] = 1;
    	}
    }

    for(auto x : umap){
    	sum += x.first;
    }
    cout << sum << endl;
	return 0;
}