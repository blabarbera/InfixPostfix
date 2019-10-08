#ifndef H_exprType
#define H_exprType

#include <string>
#include <iostream>
#include "stackType.h"

using namespace std;

class exprType
{
public:
	void showInfix();
	//Function to return the infix expression.

	void showPostfix();
	//Function to return the postfix expression.

	void getInfix(string infxStr);
	//Function to store the infix expression. 

	int precedence(const char sym1, const char sym2);
	//Function to return precedence between operators.

	bool chkOperator(const char sym);
	//Function to check if element is an operator.

	void convertToPostfix();
	//Function to convert infix expression to postfix expression.


private:
	string infx;
	string pfx = ""; //declare variables to hold infix and postfix expressions

};

void exprType::getInfix(string infxStr)
{
	infx = infxStr;
}

void exprType::showInfix()
{
	cout << "\nInfix expression: " << infx;
}

void exprType::showPostfix()
{
	cout << "\nPostfix expression: " << pfx;
}

int exprType::precedence(const char sym1, const char sym2)
{
	int pre1, pre2; //declare variables to hold operators

	if ((sym1 == '^') || (sym2 == '^') || (sym1 == '%') || (sym2 == '%')) //Check for invalid operators. Only +, -, * and / are accepted.
	{
		cout << "Valid operations are +, -, * and /. Please try again!";
	}

	if ((sym1 == '+') || (sym1 == '-')) //Check sym1 for + and - operators, these have lower precedence. 
	{
		pre1 = 0; 
	}
	else
	{
		if ((sym1 == '*') || (sym1 == '/')) //Check sym1 for * and / operators, these have higher precedence.
		{
			pre1 = 1;
		}
	}

	if ((sym2 == '+') || (sym2 == '-')) //Check sym2 for + and - operators, these have lower precedence. 
	{
		pre2 = 0;
	}
	else
	{
		if ((sym2 == '*') || (sym2 == '/')) //Check sym2 for * and / operators, these have higher precedence.
		{
			pre2 = 1;
		}
	}

	if (pre1 == pre2) //Check for equal precedence of sym1 and sym2
	{
		return 0;
	}
	else
	{
		if (pre1 > pre2) //Check for higher precedence of sym1 over sym2
		{
			return 1;
		}
		else
		{
			return -1; 
		}
	}
}

bool exprType::chkOperator(const char sym)
{
	switch(sym)	//Check each character in the string to see if it's an operator. 		
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
		break;
	default:
		return false;
	}
}

void exprType::convertToPostfix()
{
	stackType<char> myStack; //initialize stack
	int i = 0;
	bool chk = false;

	infx.append(")"); 
	myStack.push('(');

	while ((i < infx.length()) && !chk) //Loop through the infix expression
	{
		if (infx[i] != '^' && infx[i] != '%')
		{
			if (chkOperator(infx[i])) //If the infix element is an operator
			{
				if (chkOperator(myStack.top())) //If the top element in the stack is an operator
				{
					if (precedence(infx[i], myStack.top()) == 0) //If both operators have equal precedence
					{
						pfx = pfx + myStack.top(); //Write the stack element to Postfix and pop the stack
						myStack.pop();
					}
					else
					{
						if (precedence(infx[i], myStack.top()) == 1) //Else If sym1 has greater precedence than sym2
						{
							myStack.push(infx[i]); //Push the next infix element to the stack
							i++;
						}
						else
						{
							pfx = pfx + myStack.top(); //Else write the stack element to postfix and pop the stack
							myStack.pop();
						}
					}
				}
				else
				{
					myStack.push(infx[i]); //Else push the next infix element to the stack
					i++;
				}
			}
			else
			{
				if (infx[i] == ')') //Else if the infix element is ')'
				{
					while (myStack.top() != '(')
					{
						pfx = pfx + myStack.top(); //Write each stack element to postfix and pop the stack
						myStack.pop();
					}
					myStack.pop();
					i++;
				}
				else
				{
					if (infx[i] == '(') //If the next infix element is '('
					{
						myStack.push(infx[i]); //Push the element to the stack
						i++;
					}
					else
					{
						pfx = pfx + infx[i]; //Else write the next element to postfix
						i++;
					}
				}
			}
		}
		else
		{
			cout << "\nValid operations are +, -, * and /. Please try again!";
			chk = true;
			assert(chk == true);
			pfx = "Invalid Operator";
		}
	}
}

#endif // !H_exprType

