// Input : int[] arr = { 11, 11, 11, 23, 11, 37, 51, 
//                       37, 37, 51, 51, 51, 51 };
//         k = 2
// Output : 37, 51
// Explanation :
// 11's count is 4, 23 count 1, 37 count 3, 51 count 5. 
// 37 and 51 are two number that appear prime number of
// time and frequencies greater than or equal to k.

// Input : int[] arr = { 11, 22, 33 } min Occurrence = 1
// Output : -1
// None of the count is prime number of times

#include <iostream>
#include <unordered_map>
using namespace std;

bool isPrime(int x){
	bool answer = false; 
	for(int i = 2; i <= x/2; i++){
		if(x%i == 0){
			return answer;
		}
	}
	return true;
}
int main(void){
	int arr[] = { 11, 11, 11, 23, 11, 37, 51, 37, 37, 51, 51, 51, 51 };
	int k = 2;

	unordered_map< int, int> umap; 
	umap[arr[0]] = 1;
	for(int i = 1; i < 13; i++){
		if(umap[arr[i]] == 0){
			umap[arr[i]] = 1;
		}else if(umap[arr[i]] >= 1){
			umap[arr[i]]++;
		}
	}
	for(auto x : umap){
		if(isPrime(x.second) && (x.second > k)){
			cout << x.first << endl;
			continue;
		}
	}

	return 0; 
}