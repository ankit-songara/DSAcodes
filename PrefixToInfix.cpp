#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    string ele[30];
    int top;
};

void push(Stack &st, string sd)
{
    st.top++;
    st.ele[st.top] = sd;
}

string pop(Stack &st)
{
    return st.ele[st.top--];
}

int main()
{
    Stack s;
    s.top = -1;
    string c,d="";
    cin >> c;
    int i = c.size() - 1;
    while (i >= 0)
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
        {
            d.push_back(c[i]);
            push(s, d);
            d.pop_back();
        }
        else
        {
            string s1 = pop(s);
            string s2 = pop(s);
            push(s, s1 + c[i] + s2);
        }
        i--;
    }
    cout << pop(s);
}