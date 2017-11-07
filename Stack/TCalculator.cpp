#include "TCalculator.h"



TCalculator::TCalculator(string str)
{
	infix = str;
	postfix = "";
}
bool TCalculator::Check()
{
	stc.Clear();
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] = '(')
			stc.Push('(');
		if (infix[i] = ')')
		{
			if (stc.IsEmpty())
				return false;
			stc.Pop();
		}
	}
	if (stc.IsEmpty())
		return true;
	else
		return false;
}
void TCalculator::ToPostfix()
{
	stc.Clear();
	string buf = '(' + infix + ')';
	for (int i = 0; i < buf.size(); i++)
	{
		if (buf[i] == '(')
		{
			stc.Push('(');
		}
		if (buf[i] >= '0' && buf[i] <= '9' || buf[i] == '.')
			postfix += buf[i];
		if (buf[i] == ')')
		{
			postfix += ' ';
			char el = stc.Pop();
			while (el != '(')
			{
				postfix += el;
				el = stc.Pop();
			}
		}
		if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/' || buf[i]=='^')
		{
			postfix += ' ';
			if (stc.Top() != '(')
			{
				while (Priority(stc.Top()) >= Priority(buf[i]))
				{
					if (stc.Top() == '(')
						break;
					postfix += stc.Pop();
				}
				stc.Push(buf[i]);
			}
			if (stc.Top() == '(')
				stc.Push(buf[i]);
		}
	}
}
 int Priority(char el)
{
	 char index = el;
	 switch (index)
	 {
	 case '+':
		 return 1;
	 case '-':
		 return 1;
	 case '*':
		 return 2;
	 case '/':
		 return 2;
	 case '^':
		 return 3;
	 }
}
 double TCalculator::Calculate()
 {
	 TStack<double> number;
	 string el;
	 double fo, so,res;
	 for (int i = 0; i < postfix.size(); i++)
	 {
		 if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
		 {
			 switch (postfix[i])
			 {
			 case '+':
				 so = number.Pop();
				 fo = number.Pop();
				 res = fo + so;
				 number.Push(fo+so);
				 break;
			 case '-':
				 so = number.Pop();
				 fo = number.Pop();
				 number.Push(fo - so);
				 break;
			 case '*':
				 so = number.Pop();
				 fo = number.Pop();
				 number.Push(fo * so);
				 break;
			 case '/':
				 so = number.Pop();
				 fo = number.Pop();
				 number.Push(fo / so);
				 break;
			 }
		 }

		 if (postfix[i] != ' ' && postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/')
			 el += postfix[i];
		 if (postfix[i] == ' ' && el!="")
		 {
			 number.Push(atof(el.c_str()));
			 el = "";
		 }
		
	 }
	 return number.Pop();
 }
 string TCalculator::WritePost()
 {
	 return postfix;
 }
TCalculator::~TCalculator()
{
}
