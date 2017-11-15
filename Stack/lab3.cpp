#include <iostream>
#include "TStack.h"
#include "TCalculator.h"
	
void main()
{
	try
	{
		string mystr;
		//cin >> mystr;
		mystr = "(0.2*10+3)^2";
		TCalculator a(mystr);
		a.expr();
		a.ToPostfix();
		a.WritePost();
		cout << endl << a.Calculate();
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
}