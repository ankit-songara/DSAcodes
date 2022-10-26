#include <iostream>
#include<queue>
using namespace std;

struct btnode
{
    struct btnode *lc = NULL;
    int data;
    struct btnode *rc = NULL;
};

typedef struct btnode *btptr;

void create(btptr &T, int n)
{
    cin >> n;
    if (n == 0)
    {
        return;
    }
    else
    {
        T = new (btnode);
        T->data = n;
        create(T->lc, n);
        create(T->rc, n);
    }
}

int arr[50];
void lvl(btptr T,int mx_lvl,int min_lvl,int asc_lvl, int dec_lvl,int uns_lvl)
{
    if(T==NULL)
    {
        return;
    }
    else
    {
        if(T->data >mx_lvl)
        {
            mx_lvl=T->data;
        }

        if(T->data<min_lvl)
        {
            min_lvl=T->data;
        }
    }
}