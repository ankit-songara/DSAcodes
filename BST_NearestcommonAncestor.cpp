#include <bits/stdc++.h>
using namespace std;

struct bstnode
{
    bstnode *lc;
    int data;
    bstnode *rc;
};

typedef bstnode *BSTPTR;

void insert(BSTPTR &T, int k)
{
    if (T == NULL)
    {
        T = new (bstnode);
        T->data = k;
        T->lc = NULL;
        T->rc = NULL;
    }
    else
    {
        if (k < T->data)
        {
            insert(T->lc, k);
        }
        else
        {
            insert(T->rc, k);
        }
    }
}

BSTPTR nearAncestors(BSTPTR T, int n1, int n2)
{
    if (T == NULL)
    {
        return NULL;
    }

    if (T->data < n1 && T->data < n2)
    {
        return nearAncestors(T->rc, n1, n2);
    }

    if (T->data > n1 && T->data > n2)
    {
        return nearAncestors(T->lc, n1, n2);
    }

    return T;
}

int main()
{
    int n1=0, n2=0,n;
    BSTPTR T2, a;
    T2 = NULL;
    a = NULL;
    while (n != -1)
    {
        cin >> n;
        if (n == -1)
            break;
        insert(T2, n);
    }
    while (n1>=0 && n2>=0)
    {
        cin >> n1 >> n2;
        if (n1== -1 && n2 == -1)
        {
            break;
        }
        a = nearAncestors(T2, n1,n2);
        cout << a->data;
    }
}