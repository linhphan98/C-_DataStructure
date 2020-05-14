// S.length = T.length 
// and
// S[i] = T[i] + K for 
// 1 <= i <= S.length  for a constant integer K
// Input  : str[] = {"acd", "dfg", "wyz", "yab", "mop",
//                  "bdfh", "a", "x", "moqs"};

// Output : a x
//          acd dfg wyz yab mop
//          bdfh moqs

#include <iostream>
#include <unordered_map>
#include <vector>
#include <math.h>
using namespace std;

int compareTwo(char one, char two){
	int compare = 0;
	if(one - two < 0){
		compare = (one - two) + 26;
	}else{
		compare = one - two;
	}
	return compare; 
}
int main(void){
	string str[10] = {"acd", "dfg", "wyz", "mop", "yab", "wyac" , "bdfh", "a", "x", "moqs"};
	unordered_map <int, vector<string> > umap;

	for(int i = 0; i < 10; i++){
		if(str[i].length() == 1){
			umap[str[i].length()].push_back(str[i]);
		}else{
			if(umap[str[i].length()].size() == 0){
				umap[str[i].length()].push_back(str[i]);
			}else{
				int count = 0;
				for(int x = 0; x < str[i].length(); x++){
					if(compareTwo(umap[str[i].length()][0][x], umap[str[i].length()][0][0]) 
						== compareTwo(str[i][x], str[i][0])){
						count++;
					}
				}
				if(count == str[i].length()){
					umap[str[i].length()].push_back(str[i]);
				}
			}
		}
	}
	for(auto x : umap){
		cout << x.first << " ";
		for(int i = 0; i < x.second.size(); i++){
			cout << x.second[i] << " ";
		}
		cout << endl;
	}
	return 0;
}