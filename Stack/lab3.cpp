#include <iostream>
#include "TStack.h"
#include "TCalculator.h"
	
void main()
{
	try
	{
		string mystr;
		mystr = "3+(2+(2+3)*4)";
		TCalculator a(mystr);
		a.ToPostfix();
		a.WritePost();
		a.Calculate();
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