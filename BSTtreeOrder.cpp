#include <iostream>
using namespace std;

struct bstnode
{
    struct bstnode *lc;
    int data;
    struct bstnode *rc;
};

typedef struct bstnode *BSTPTR;

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

void preorderprint(BSTPTR T)
{
    if (T != NULL)
    {
        cout << T->data << " ";
        preorderprint(T->lc);
        preorderprint(T->rc);
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

void postorderprint(BSTPTR T)
{
    if (T != NULL)
    {
        postorderprint(T->lc);
        postorderprint(T->rc);
        cout << T->data << " ";
    }
}

void find(BSTPTR T, int k)
{
    if (T == NULL)
    {
        cout << "0";
    }

    else if (T->data == k)
    {
        cout << "1";
    }

    else
    {
        if (k < T->data)
        {
            find(T->lc, k);
        }

        else if (k > T->data)
        {
            find(T->rc, k);
        }
    }
}

int min(BSTPTR T)
{
    if (T->lc != NULL)
        return min(T->lc);
    else
        return T->data;
}

int max(BSTPTR T)
{
    if (T->rc != NULL)
        return max(T->rc);
    else
        return T->data;
}

int main()
{
    BSTPTR T2;
    T2 = NULL;
    int n,a,b;
    while(n!=-1)
    {
        cin>>n;
        if(n==-1) break;
        insert(T2,n);
    }
    preorderprint(T2);
}