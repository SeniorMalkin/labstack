#pragma once
# include "TStack.h"
# include <cstdlib>
# include <cmath>
class TCalculator
{
	string infix;
	string postfix;
	TStack<char> stc;

public:
	TCalculator(string str = " ");
	bool Check();
	void expr();
	void ToPostfix();
	friend int Priority(char el);
	string WritePost();
	double Calculate();
	~TCalculator();
};

