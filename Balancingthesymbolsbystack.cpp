#include <iostream>
#include <string>
using namespace std;
struct stack
{
	int size;
	int top;
	char element[50];
};

void push(stack &s, char c)
{
	if (s.top == s.size - 1)
	{
		cout << "Stack is full";
	}
	else
	{
		s.top++;
		s.element[s.top] = c;
	}
}

int pop(stack &s)
{
	if (s.top == -1)
	{
		cout << "Stack is empty";
	}
	else
	{
		return (s.element[s.top--]);
	}
}

int peep(stack &s)
{
	if (s.top == -1)
	{
		cout << "Stack is empty";
	}
	else
	{
		return s.element[s.top];
	}
}

int main()
{
	stack S;
	S.size = 50;
	S.top = -1;
	string n;
	int i = 0;
	getline(cin, n);
	while (i < n.size())
	{
		if (n[i] == '{')
		{
			push(S, n[i]);
		}

		if (n[i] == '}')
		{
			if (S.top != -1 && S.element[S.top] == '{')
			{
				pop(S);
			}
			else
			{
				cout << "0" << endl;
				return 0;
			}
		}
		i++;
	}

	if (S.top == -1)
	{
		cout << '1' << endl;
	}
	else
	{
		cout << '0' << endl;
	}
}
