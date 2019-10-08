#include "stackType.h"
#include "exprType.h"
#include <string>

using namespace std;

int main()
{
	exprType myExpr; //create expression object

	string infxStr; //declare variable to hold infix expression

	cout << "Enter an expression: "; //prompt user to enter expression
	getline(cin, infxStr);

	myExpr.getInfix(infxStr); //Set infix expression
	myExpr.showInfix(); //Return infix expression
	myExpr.convertToPostfix(); //Convert infix expression to postfix expression
	myExpr.showPostfix(); //Return postfix expression. 

	return 0;
}