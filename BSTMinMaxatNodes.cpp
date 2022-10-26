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

int max_subtree(BSTPTR T)
{
    if(T->rc==NULL) return T->data;
    else
    return max_subtree(T->rc);
}

int min_subtree(BSTPTR T)
{
    if(T->lc==NULL) return T->data;
    else
    return min_subtree(T->lc);
}
void MinMax(BSTPTR T,int min,int max)
{
    int tx,tn;
    if (T == NULL)
    {
        return;
    }
    else
    {
        if(T->lc)
        {
            tn=max_subtree(T->lc);
            tn++;
            MinMax(T->lc,min,T->data-1);
        }
        else
        tn=0;
        
        if(T->rc)
        {
            tx=min_subtree(T->rc);
            tx--;
            MinMax(T->rc,T->data+1,max);
        }
        else
        tx=9999;
        tn=(tn>min)?tn:min;
        tx=(tx<max)?tx:max;
        cout<<T->data<<" "<<tn<<" "<<tx<<endl;
    }
}

int main()
{
    BSTPTR T2;
    T2 = NULL;
    int n;
    while (n != -1)
    {
        cin >> n;
        if (n == -1)
            break;
        insert(T2, n);
    }
    MinMax(T2,0,9999);
}