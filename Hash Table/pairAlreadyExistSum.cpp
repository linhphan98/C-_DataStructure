// Input : arr[] = {2, 8, 7, 1, 5};
// Output : 2 5
//          7 1    
     
// Input : arr[] = {7, 8, 5, 9, 11};
// Output : Not Exist
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main(void){
	int arr[] = {7, 8, 5, 9, 11};;
	queue<int> result; 
	unordered_map<int, int> map; 
	for(int x : arr){
		map[x] = 1;
	}

	for(int i = 0; i < 5; i++){
		for(int x = i + 1; x <= 4 ; x++){
			try{
				if(map.at(arr[i] + arr[x]) == 1){
					result.push(arr[i]); 
					result.push(arr[x]);
					break;
				}
			}catch(exception e){
				continue;
			}
		}
	}

	if(result.empty()){
		cout << "Not Exist" << endl;
	}else{
		while(!result.empty()){
			cout << result.front() << " ";
			result.pop();
			cout << result.front() << endl;
			result.pop();
		}
	}
	
	return 0; 
}