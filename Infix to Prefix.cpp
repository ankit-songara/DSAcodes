#include<iostream>
#include<string>
using namespace std;
struct stack
{
	int size;
	int top;
	char element[50];
};

void push(stack &s, char x)
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
	stack S;
	int i=0;
	S.size=50;
	S.top=-1;
	string n;
	cin>>n;
	while(i<n.size())
	{
		push(S,n[i]);
		i++;
	}
	i=0;
	while(i<n.size())
	{
		n[i]=pop(S);
		i++;
	}
	i=0;
	for(i=0;i<n.size();i++)
	{
		if(n[i]=='(')
		{
			n[i]=')';
		}
		
		else if(n[i]==')')
		{
			n[i]='(';
		}
	}
	
	string result;
    for(int i=0;i<n.size();i++){
        char c=n[i];
        if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')){
            result+=c;
        }
        else if(c==')'){
            push(S,c);
        }else if(c=='('){
            while(peep(S)!=')'){
                result+=peep(S);
                pop(S);
            }pop(S);
        }else{
            while(S.top!=-1 && prec(n[i])<prec(peep(S))){
                result+=peep(S);
                pop(S);
            }push(S,c);
        }
    }
    while(S.top!=-1) {
        result += peep(S);
        pop(S);
    }
    
    for(i=0;i<result.size();i++)
    {
    	push(S,result[i]);
	}
	
	for(i=0;i<result.size();i++)
    {
    	result[i]=pop(S);
	}
	
	for(i=0;i<result.size();i++)
	{
		cout<<result[i];
	}


	
	

}
