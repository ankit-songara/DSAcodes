#include<iostream>
#include<string>
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

char peep(stack &s)
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
	int i=0;
	int r,opnd2,opnd1;
	S.size=50;
	S.top=-1;
	string n;
	cin>>n;
	
	while(i<n.size())
	{
		if(n[i]!='*' && n[i]!='+' && n[i]!='-' && n[i]!='/' )
		{
			push(S,n[i]-'0');
		}
		
		else
		{
			opnd2 =pop(S);
			opnd1 =pop(S);
			switch (n[i])
			{
				case '*':
					r=(opnd2)*(opnd1);
					break;
				case '+':
					r=(opnd2)+(opnd1);
					break;
				case '-':
					r=(opnd2)-(opnd1);
					break;
				case '/':
					r=(opnd2)/(opnd1);
					break;
					
			}
			push(S,r);
			
		}
		i++;
	}
	while(S.top>=0)
	{
		cout<<pop(S)<<" ";
	}
	
	
}
