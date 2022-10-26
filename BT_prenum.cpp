#include <bits/stdc++.h>
using namespace std;
struct btnode
{
    int data;
    int AT = 0;
    int DT = 0;
    int size = 0;
    int height = 0;
    int depth = 0;
    struct btnode *LC = NULL;
    struct btnode *RC = NULL;
};
typedef struct btnode *BTPTR;
void create(BTPTR &T, int n)
{
    cin >> n;
    if (n == 0)
        return;
    else
    {
        T = new (btnode);
        T->data = n;
        create(T->LC, n);
        create(T->RC, n);
    }
}
void update(BTPTR &T, int &n)
{
    if (T)
    {
        T->AT = n++;
        update(T->LC, n);
        update(T->RC, n);
        T->DT = n++;
    }
    else
        return;
}
void sizeOFBTREE(BTPTR &T)
{
    if (T->AT > T->DT)
    {
        T->size = (T->AT - T->DT) / 2;
    }
    else
    {
        T->size = (T->DT - T->AT) / 2;
    }
    if (T->LC)
        sizeOFBTREE(T->LC);
    if (T->RC)
        sizeOFBTREE(T->RC);
}
void print(BTPTR T)
{
    cout <<T->data<<" "<<T->size<<" "<<T->height << " " << T->depth << "\n";
    if (T->LC)
        print(T->LC);
    if (T->RC)
        print(T->RC);
}
int height(BTPTR T)
{
    if (T == NULL)
        return -1;
    else
        return 1 + max(height(T->LC), height(T->RC));
}
void updateheight(BTPTR &T, int &maxHeight, int n)
{
    if (T)
    {
        T->depth = n;
        T->height = maxHeight - n;
        updateheight(T->LC, maxHeight, n+1);
        updateheight(T->RC, maxHeight, n+1);
    }
    else
        return;
}
int main()
{
    BTPTR T = NULL;
    int n;
    create(T, n);
    n = 0;
    update(T, n);
    sizeOFBTREE(T);
    int max_height = height(T);
    updateheight(T, max_height, 0);
    print(T);
}