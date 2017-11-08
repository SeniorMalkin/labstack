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
	string buf = "(";
	buf+=infix;
	buf+=")";
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
		 if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		 {
			 so = number.Pop();
			 fo = number.Pop();
			 switch (postfix[i])
			 {
			 case '+':
				 number.Push(fo+so);
				 break;
			 case '-':
				 number.Push(fo - so);
				 break;
			 case '*':
				 number.Push(fo * so);
				 break;
			 case '/':
				 number.Push(fo / so);
				 break;
			 case '^':
				  number.Push(pow(fo,so));
				 break;

			 }
		 }

		 if(postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.')
			 el += postfix[i];
		 if (postfix[i] == ' ' && el.size()!=0)
		 {
			 number.Push(atof(el.c_str()));
			 el = "";
		 }
		
	 }
	 return number.Pop();
 }
 string TCalculator::WritePost()
 {
	 int i=0;
	 char* tmp;
	 strtod(&infix[0],&tmp);
	 if((tmp+1)[0]>='0' && (tmp+1)[0]<='9' || (tmp+1)[0]=='(')
		 i++;
	 return postfix;
 }
TCalculator::~TCalculator()
{
}
