#include <bits/stdc++.h>
using namespace std;
struct btnode
{
    btnode *lc;
    int data;
    btnode *rc;
};
typedef struct btnode *btptr;
void insert(btptr &T)
{
    int z;
    cin >> z;
    if (z == 0)
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

void non_leaf(btptr T, int &a, int &b)
{
    if (T == NULL)
    {
        return;
    }
    if (T->lc == NULL && T->rc == NULL)
    {
        a = a + 1; // non leaf nodes
    }
    else
    {
        b = b + 1; // leaf nodes
    }
    non_leaf(T->lc, a, b);
    non_leaf(T->rc, a, b);
}

void child(btptr T, int &a, int &b)
{
    if (T == NULL)
    {
        return;
    }
    if (T->lc != NULL && T->rc != NULL)
    {
        a = a + 1;
    }

    if ((T->lc != NULL && T->rc == NULL) || (T->lc == NULL && T->rc != NULL))
    {
        b = b + 1;
    }
    child(T->lc, a, b);
    child(T->rc, a, b);
}

void lc_child(btptr T, int &a, int &b)
{
    if (T == NULL)
    {
        return;
    }
    if (T->lc != NULL)
    {
        a = a + 1;
    }

    if (T->rc != NULL)
    {
        b = b + 1;
    }
    lc_child(T->lc, a, b);
    lc_child(T->rc, a, b);
}

void ex_left(btptr T)
{
    queue<btptr> q;
    q.push(T);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            btptr temp = q.front();
            q.pop();

            if (i == 1)
            {
                cout << temp->data << " ";
            }

            if (temp->lc != NULL)
            {
                q.push(temp->lc);
            }

            if (temp->rc != NULL)
            {
                q.push(temp->rc);
            }
        }
    }
}

void ex_right(btptr T)
{
    queue<btptr> q;
    q.push(T);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            btptr temp = q.front();
            q.pop();

            if (i == n)
            {
                cout << temp->data << " ";
            }

            if (temp->lc != NULL)
            {
                q.push(temp->lc);
            }

            if (temp->rc != NULL)
            {
                q.push(temp->rc);
            }
        }
    }
}

int main()
{
    btptr T2;
    T2 = NULL;
    insert(T2);
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    non_leaf(T2, a, b);
    cout << b << " " << a << endl;
    child(T2, c, d);
    cout << c << " " << d << endl;
    lc_child(T2, e, f);
    cout << e << " " << f << endl;
    ex_left(T2);
    cout<<endl;
    ex_right(T2);
}
