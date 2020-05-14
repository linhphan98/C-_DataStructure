// order of operation 
// 1) Parentheses() {} []
// 2) Exponents (right to left)
// 3) Multiplication and division (left to right)
// 4) Addition and subtraction (left to right)
// infix 		prefix 			postfix
// 2+3			+2 3 			2 3 +
// p-q			-p q 			p q -
// a+b*c		+a *b c			abc * +
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

string InfixToPostfix(string expression);
int HasHigherPrecedence(char top, char current);
bool IsOperator(char C);
bool IsOperand(char C);

int main(void){
	string expression;
	cout << "Enter Infix Expression" << endl;
	cin >> expression;
	string postfix = InfixToPostfix(expression);
	cout << "Output = " << postfix << endl;
	return 0;
};

string InfixToPostfix(string expression){
	stack<char> S; 
	string postfix = ""; 
	for(int i = 0; i < expression.length(); i++){
		// if character is a space or , move on
		if(expression[i] == ' ' || expression[i] == ',') continue;

		// if character is operator, pop two elements from the stack, perform the operation and push the result
		else if(IsOperator(expression[i])){
			// stop when the stack is empty or '(' is the next one in stack or the top has higher priority than the current (* > +)
			// then pop everything out until '(' or empty or same priority or current is higher 
			while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i])){
				postfix += S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		// else if character is an operand 
		else if(IsOperand(expression[i])){
			postfix += expression[i];
		}else if (expression[i] == '('){
			S.push(expression[i]);
		}else if(expression[i] == ')'){
			while(!S.empty() && S.top() != '('){
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()){
		postfix += S.top();
		S.pop();
	}
	return postfix;
};

// Verifying whether a character is english letter or numeric digit 
bool IsOperand(char C){
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
};

// Function to verify whether a character is operator symbol or not 
bool IsOperator(char C){
	if((C == '+') || (C == '-') || (C == '/') || (C == '*') || (C == '$')) 
		return true;

	return false;
};

// Function to verify whether an operator is right associative or not 
int IsRightAssociative(char op){
	if(op == '$') return true;
	return false;
};

// Function to get weight of an operator. An operator with higher weight will have higher priorities
int GetOperatorWeight(char op){
	int weight = -1;
	switch(op){
		case '+':
		case '-': 
			weight = 1;
		break;
		case '/':
		case '*':
			weight = 2;
		break;
		case '$':
			weight = 3;
		break;
	}
	return weight;
};

// Function to perform an operation and return output 
int HasHigherPrecedence(char top, char current){
	int op1Weight = GetOperatorWeight(top);
	int op2Weight = GetOperatorWeight(current);

	// if operators have equal weight, return true if they are left associative
	// return false, if right associative because we are check the top of the stack and current character in the string
	// equal weight, the inside the stack should have priority 
	if(op1Weight == op2Weight){
		// IsRightAssociative, I think, always returns false so the function will always return false if they have equal weight
		if(IsRightAssociative(top)) return false;
		else return true;
	}

	return op1Weight > op2Weight ? true: false;
}



// Implement this method when there is two number like 12 14 22 as an operand 
// else if(IsNumericDigit(expression[i])){
// 	// Extract the numeric operand from the string
// 	// Keep incrementing i as long as you are getting a numeric digit. 
// 	int operand = 0; 
// 	while(i<expression.length() && IsNumericDigit(expression[i])) {
// 		// For a number with more than one digits, as we are scanning from left to right. 
// 		// Everytime , we get a digit towards right, we can multiply current total in operand by 10 
// 		// and add the new digit. 
// 		operand = (operand*10) + (expression[i] - '0'); 
// 		i++;
// 	}
// 	// Finally, you will come out of while loop with i set to a non-numeric character or end of string
// 	// decrement i because it will be incremented in increment section of loop once again. 
// 	// We do not want to skip the non-numeric character by incrementing i twice. 
// 	i--;

// 	// Push operand on stack. 
// 	S.push(operand);
// }





