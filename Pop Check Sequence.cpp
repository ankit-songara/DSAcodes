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
	int x,i=0,a,b=0;
	cin>>x;
	int pushs[x];
	int pops[x];
	S.size=50;
	S.top=-1;
	while(i<x)
	{
		cin>>pushs[i];
		i++;
	}
    i = 0;
	while(i<x)
	{
		cin>>pops[i];
		i++;
	}    
	i=0;
	while(i<x)
	{
		a=pushs[i];
		push(S,a);
		while(b<x && peep(S)==pops[b])
		{
			pop(S);
			b++;
		}
		i++;
	}
	
	if(S.top==-1)
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}

	
}
