#include<iostream>
using namespace std;
struct stack
{
	int size;
	int top;
	int element[50];
};

void push(stack &s, int x)
{
	if(s.top==s.size-1)
	{
		cout<<"Stack is full";
	}
	else
	{
		s.top++;
		s.element[s.top]=x;
	}
}

int pop(stack &s)
{
	if(s.top==-1)
	{
		cout<<"Stack is empty";
	}
	else
	{
		return(s.element[s.top--]);
	
	}
}

int peep(stack &s)
{
	if(s.top==-1)
	{
		cout<<"Stack is empty";
	}
	else
	{
		return s.element[s.top];
	}
}

int main()
{
	stack S;
	int i=0,a,b=0;
	int pushs[6];
	int pops[6];
	S.size=50;
	S.top=-1;
	while(i<6)
	{
		cin>>pushs[i];
		i++;
	}
    i = 0;
    
	while(i<6)
	{
		cin>>pops[i];
		i++;
	}    
	i=0;
	while(i<6)
	{
		a=pushs[i];
		push(S,a);
		cout<<'S';
		while(b<6 && peep(S)==pops[b])
		{
			pop(S);
			b++;
			cout<<'X';
		}
		i++;
	}
}
