#include <bits/stdc++.h>
using namespace std;
struct btnode
{
    btnode *lc;
    char data;
    btnode *rc;
};

typedef struct btnode *btptr;

void insert(btptr &T)
{
    char z;
    cin >> z;
    if (z=='#')
    {
        return;
    }
    else
    {
        T = new btnode();
        T->lc = NULL;
        T->data = z;
        T->rc = NULL;
        insert(T->lc);
        insert(T->rc);
    }
}
void preorder(btptr T)
{
    int count=0;
    if (T == NULL)
        return;
    stack<btptr> s;
    s.push(T);
    while (!s.empty())
    {
        T = s.top();
        s.pop();
        cout << T->data;
        if (T->rc != NULL)
        {
            s.push(T->rc);
            count++;
        }
        if (T->lc != NULL)
        {
            s.push(T->lc);
            count++;
        }
    }
    cout<<endl;
    cout<<count+1;
}

void inorder(btptr T)
{
    int cnt=0;
    stack<btptr> s;
    btptr crr = T;
    while (!s.empty() || crr != NULL)
    {
        while (crr != NULL)
        {
            s.push(crr);
            cnt++;
            crr = crr->lc;
        }

        crr = s.top();
        s.pop();
        cout << crr->data;
        crr = crr->rc;
    }
    cout<<endl;
    cout<<cnt;
}

int main()
{
    btptr T2;
    insert(T2);
    preorder(T2);
    cout<<endl;
    inorder(T2);
}
