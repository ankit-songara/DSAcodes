#include<iostream>
using namespace std;
struct stack
{
	int size;
	int top;
	int element[50];
	char ele[50];
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

void pushs(stack &s, char c)
{
	if(s.top==s.size-1)
	{
		cout<<"Stack is full";
	}
	else
	{
		s.top++;
		s.ele[s.top]=c;
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

int pops(stack &s,char c)
{
	if(s.top==-1)
	{
		cout<<"Stack is empty";
	}
	else
	{
		return(s.ele[s.top--]);
	
	}
}

int prec(char c) {
    if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
int main()
{
	stack valS,opS;
	valS.size=50;
	opS.size=50;
	valS.top=-1;
	opS.top=-1;
	int i=0,opnd2,opnd1,r;
	char a;
	string n;
	cin>>n;
	while(i<n.size())
	{
		if(n[i]>='0' && n[i]<='9')
		{
			push(valS,n[i]-'0');
		}
		
		else
	    {
	    	char thisOp =n[i];
		    while(opS.top!=-1 && prec(opS.ele[opS.top])>=prec(thisOp))
			{
				a=pops(opS,n[i]);
				opnd2 =pop(valS);
			    opnd1 =pop(valS);
		        switch (a)
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
			    push(valS,r);
			}
		    pushs(opS,thisOp);
		}
		i++;
	}
		
	while(opS.top!=-1)
	{
		a=pops(opS,a);
		opnd2 =pop(valS);
		opnd1 =pop(valS);
		switch (a)
		{
			case '*':
				r=(opnd2)*(opnd1);
				break;
			case '+':
				r=(opnd2)+(opnd1);
				break;
			case '-':
				r=(opnd1)-(opnd2);
				break;
			case '/':
				r=(opnd2)/(opnd1);
				break;
		}
		push(valS,r);
	}
	cout<<pop(valS);

}
