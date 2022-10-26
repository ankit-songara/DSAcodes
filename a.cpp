#include <bits/stdc++.h>
using namespace std;
typedef struct bstnode
{
    bstnode *lc;
    char data;
    bstnode *rc;
} * bstptr;
bstptr z;
void insert(bstptr &t)
{
    char k;
    cin >> k;
    if (k == '#')
        return;
    else
    {
        t = new bstnode();
        t->data = k;
        t->lc = NULL;
        t->rc = NULL;
        insert(t->lc);
        insert(t->rc);
    }
}
char hdarr[1000];
int lvl[100];
void topview(bstptr z, int hd, int &mina, int &maxa)
{
    if (z == NULL)
        return;
    if (hd < mina || hd > maxa)
    {
        hdarr[hd] = z->data;
    }
    mina = min(mina, hd);
    maxa = max(maxa, hd);
    topview(z->lc, hd - 1, mina, maxa);
    topview(z->rc, hd + 1, mina, maxa);
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
    insert(z);
    int min = 99;
    int max = -99;
    topview(z, 0, min, max);
    for (int i = min; i <= max; i++)
    {
        cout << hdarr[i] << " ";
    }
}