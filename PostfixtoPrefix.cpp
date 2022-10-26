#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    string ele[30];
    int top;
};

void push(Stack &st, string s1)
{
    st.top++;
    st.ele[st.top] = s1;
}
string pop(Stack &st)
{
    return st.ele[st.top--];
}

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }

    else if (c == '*' || c == '/')
    {
        return 2;
    }

    else if (c == '+' || c == '-')
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

void infinixtopostfix(string post)
{
    stack<char> st;
    string result;
    for (int i = post.length()-1; i>=0; i--)
    {
        char c = post[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(post[i]) <precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    for (int i=result.length()-1;i>= 0;i--)
    {
        cout<<result[i];
    }
    
}

int main()
{
    Stack st;
    int i=0; 
    string res;
    st.top=-1;
    string c,d="";
    cin>>c;
   	while(c[i]!='\0'){
   		if(c[i]>='A' && c[i]<='Z'){
   			d.push_back(c[i]);
            push(st,d);
            d.pop_back();
		   }
		   else{
		   	string s1=pop(st);
		   	string s2=pop(st);
		   	push(st,s2+c[i]+s1);
		
		   }
	   i++;
	}
	c=pop(st);
    cout<<c;
    infinixtopostfix(c);


}