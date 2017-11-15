#include <iostream>
#include "TStack.h"
#include "TCalculator.h"
	
void main()
{
	try
	{
		string mystr;
		//cin >> mystr;
		mystr = "((2+3)+3)*3";
		TCalculator a(mystr);
		a.Check();
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