#include <iostream>
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
    stack s;
    s.size=50;
    s.top=-1;
    int i=0;
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    
    i=0;
    while (i < 4)
    {
        push(s,arr[i]);
        if(peep(s)==arr[i+1])
        {
            pop(s);
            i=i+2;
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        arr[i] =peep(s);
        pop(s);
    }

    for (int i = 3; i >= 0; i--)
    {
        cout << arr[i];
    }
}