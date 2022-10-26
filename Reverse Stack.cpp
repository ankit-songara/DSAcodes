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
	stack s1,s2;
	s1.size=10;
	s2.size=10;
	s1.top=-1;
	s2.top=-1;
	int n[6],i=0,a;
	for(int i=0;i<6;i++)
	{
		cin>>n[i];
	}
	i=6;
	while(i>=0)
	{
		push(s1,n[i]);
		i--;
	}
	i=0;
	while(i<6)
	{
		a=pop(s1);
		push(s2,a);
		i++;
	}
	
	while(s2.top>=0)
	{
		cout<<pop(s2)<<" ";
	}
}
