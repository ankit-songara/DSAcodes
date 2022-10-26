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
    for (int i = 0; i < post.length(); i++)
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
            while (!st.empty() && precedence(post[i]) <= precedence(st.top()))
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
    cout << result << endl;
}

int main()
{
    Stack s;
    s.top = -1;
    string c;
    cin >> c;
    int i = c.size() - 1;
    while (i >= 0)
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
        {
            char c1 = c[i];
            char ch[1] = {c1};
            push(s, ch);
        }
        else
        {
            string s1 = pop(s);
            string s2 = pop(s);
            push(s, s1 + c[i] + s2);
        }
        i--;
    }
    string post = pop(s);
    infinixtopostfix(post);
}