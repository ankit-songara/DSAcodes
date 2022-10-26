#include <iostream>
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
        if (k != 0)
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
}

void preorderprintSerialization(BSTPTR T)
{
    if (T == NULL)
    {
        cout << "0"
             << " ";
    }
    else
    {
        cout << T->data << " ";
        preorderprintSerialization(T->lc);
        preorderprintSerialization(T->rc);
    }
}

void inorderprint(BSTPTR T)
{
    if (T != NULL)
    {
        inorderprint(T->lc);
        cout << T->data << " ";
        inorderprint(T->rc);
    }
}

int main()
{
    BSTPTR T2, T1;
    T2 = NULL;
    T1 = NULL;
    int n, t=19,a;
    while (n != -1)
    {
        cin >> n;
        if (n == -1)
            break;
        insert(T2, n);
    }
    preorderprintSerialization(T2);
}