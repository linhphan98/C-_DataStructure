// Parenthesis: Last open first closed [(]) wrong 
// Scan from left to right
// if opening symbol, add to the end list. If closing symbol, remove last opening symbol 
// must end with an tempty list

#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

bool checkBalancedParenthesis(string line){
	int size = line.length();
	stack<char> S; 
	for(int i = 0; i < size; i++){
		if((line[i] == '{') || (line[i] == '(') || (line[i] == '[')){
			S.push(line[i]);
		}else if((line[i] == '}') || (line[i] == ')') || (line[i] == ']')){
			switch(line[i]){
				case '}':
					line[i] = '{';
				break;
				case ')':
					line[i] = '(';
				break;
				case ']':
					line[i] = '[';
				break;
			}
			if((S.empty()) || (S.top() != line[i])){
				return false;
			}else{
				S.pop();
			}
		}
	}
	if(S.empty()){
		return true;
	}else{
		return false;
	}
};

int main(void){
	string line; 
	cin >> line;
	bool answer = checkBalancedParenthesis(line);
	cout << answer;
}



