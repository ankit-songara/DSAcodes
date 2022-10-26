#include<bits/stdc++.h>
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
int pathArr[50];
void path(BSTPTR T, int i)
{   
    if(T==NULL)
    {
        return;
    }
    pathArr[i]=T->data;
    i++;

    if(T->lc==NULL && T->rc==NULL)
    {
        for(int j=0;j<i;j++)
        {
            cout<<pathArr[j]<<" ";
        }
        cout<<endl;
    }
    else
    {
        path(T->lc,i);
        path(T->rc,i); 
    }

}

int main()
{
    BSTPTR T2;
    T2 = NULL;
    int i=0;
    int n;
    while (n != -1)
    {
        cin >> n;
        if (n == -1)
            break;
        insert(T2, n);
    }
    path(T2, 0);
}
