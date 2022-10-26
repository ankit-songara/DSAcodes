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
{   int z;
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
int arr[50];
int k = 0;
int i=0;
void print(btptr T)
{
    if (T == NULL)
    {
        return;
    }
    arr[k] = T->data;
    k++;
    print(T->lc);
    print(T->rc);
}
void btTobst(btptr T)
{
  if(T==NULL)return;
  btTobst(T->lc);
  T->data=arr[i];
  i++;
  btTobst(T->rc);
  
}

void preorderprint(btptr T)
{
    if (T != NULL)
    {
        cout << T->data << " ";
        preorderprint(T->lc);
        preorderprint(T->rc);
    }
}

int main()
{
    btptr T2, T1 = NULL;
    insert(T2);
    print(T2);
    sort(arr,arr+k);
    btTobst(T2);
    preorderprint(T2);
}