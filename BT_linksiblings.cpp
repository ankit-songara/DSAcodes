#include <iostream>
using namespace std;

struct btnode
{
    btnode *lc;
    int data;
    btnode *ns;
    btnode *rc;
};

typedef struct btnode *btptr;

void create(btptr &pt)
{
    int n;
    cin >> n;
    if (n == '0')
        return;
    else
    {
        pt = new (btnode);
        pt->lc = NULL;
        pt->data = n;
        pt->rc = NULL;
        create(pt->lc);
        create(pt->rc);
    }
}

btptr getNextRight(btptr pt)
{
    btptr temp = pt->ns;
    while (temp != NULL)
    {
        if (temp->lc != NULL)
            return temp->lc;
        if (temp->rc != NULL)
            return temp->rc;
        temp = temp->ns;
    }
    return NULL;
}

void sib(btptr pt)
{
    if (pt == NULL)
    {
        return;
    }

    pt->ns = NULL;

    while (pt != NULL)
    {
        btptr q = pt;
        while (q != NULL)
        {
            if (q->lc)
            {
                if (q->rc)
                    q->lc->ns = q->rc;
                else
                    q->lc->ns = getNextRight(q);
            }

            if (q->rc)
                q->rc->ns = getNextRight(q);
            q = q->ns;
        }
    }

    if (pt->lc != NULL)
        pt = pt->lc;
    else if (pt->rc != NULL)
        pt = pt->rc;
    else
        pt = getNextRight(pt);
}

void print(btptr pt)
{
    cout << pt->ns->data;
    if (pt->lc)
        print(pt->lc);
    if (pt->rc)
        print(pt->rc);
}
int main()
{
    btptr T2 = NULL;
    create(T2);
    sib(T2);
    print(T2);
}
