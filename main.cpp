#include "stackType.h"
#include "exprType.h"
#include <string>

using namespace std;

int main()
{
	exprType myExpr;

	string infxStr;

	cout << "Enter an expression: ";
	getline(cin, infxStr);

	myExpr.getInfix(infxStr);
	myExpr.showInfix();
	myExpr.convertToPostfix();
	myExpr.showPostfix();

	return 0;
}