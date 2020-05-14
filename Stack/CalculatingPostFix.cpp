#include <iostream>
#include <string.h>
#include <stack>

using namespace std; 

int EvaluatePostFix(string expression);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char C);
bool IsNumber(char C);

int main(void){

	string expression;
	cout << "Enter postfix expression" << endl;
	cin >> expression;
	int result = EvaluatePostFix(expression);
	cout << "Output = " << result << endl;
	return 0; 
};

int EvaluatePostFix(string expression){
	stack<int> S;
	for (int i = 0; i < expression.length(); i++){
		// scanning each from left to right 
		// if character is , or space move on 
		if(expression[i] == ',' || expression[i] == ' '){
			continue;
		}
		// if it is an operator pop two out then calculate with that two then put in the stack the result
		else if(IsOperator(expression[i])){
			// pop two out careful because of - and / will have the later one to - or / the top one 
			// because the return is char so we have to - '0' to turn it to int
			int operand2 = S.top() - '0'; S.pop();
			int operand1 = S.top() - '0'; S.pop();
			// perform operation 
			int result = PerformOperation(expression[i], operand1, operand2);
			S.push(result);
		}else if(IsNumber(expression[i])){
			S.push(expression[i]);
		}
	}
	return S.top();
};

bool IsNumber(char C){
	if(C >= '0' && C <= '9') return true;
	return false;
};

bool IsOperator(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/') return true;
	return false;
};

int PerformOperation(char operation, int operand1, int operand2){
	if(operation == '+') return operand1+operand2;
	else if(operation == '-') return operand1-operand2;
	else if(operation == '*') return operand1*operand2;
	else if(operation == '/') return operand1/operand2;

	else cout << "unexpected error" << endl;
	return -1; 
}
