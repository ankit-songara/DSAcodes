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
    if (z == '#')
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

void leftview(btptr T, int h, int &mx_lvl)
{
    if (T == NULL)
    {
        return;
    }
    if (h > mx_lvl)
    {
        mx_lvl = h;
        cout << T->data << " ";
    }
    leftview(T->lc, h + 1, mx_lvl);
    leftview(T->rc, h + 1, mx_lvl);
}

void rightview(btptr T, int h, int &mx_lvl)
{
    if (T == NULL)
    {
        return;
    }
    if (h > mx_lvl)
    {
        mx_lvl = h;
        cout << T->data << " ";
    }
    rightview(T->rc, h + 1, mx_lvl);
    rightview(T->lc, h + 1, mx_lvl);
}

char hdarr[1000];
int lvl[100];
void topview(btptr z, int hd, int &mina, int &maxa)
{
    if (z == NULL)
        return;
    if (hd < mina || hd > maxa)
    {
        hdarr[hd] = z->data;
    }
    mina = min(mina, hd);
    maxa = max(maxa, hd);
    if (z->rc != NULL)
    {
        topview(z->lc, hd - 1, mina, maxa);
    }

    if (z->lc != NULL)
    {
        topview(z->rc, hd + 1, mina, maxa);
    }
}

/* void topview(bstptr z,int hd,int &mina,int &maxa,int level){
    if(z==NULL)return;
    if(level>=lvl[hd]){
      lvl[hd]=level;
hdarr[hd]=z->data;
  }
  mina=min(mina,hd);maxa=max(maxa,hd);
    topview(z->lc,hd-1,mina,maxa,level+1);
    topview(z->rc,hd+1,mina,maxa,level+1);
} */

int main()
{
    btptr T2;
    T2 = NULL;
    insert(T2);
    int mx_lvl=-1;
    rightview(T2,0,mx_lvl);
}