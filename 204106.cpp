#include <bits/stdc++.h>
using namespace std;

// bst
struct bstnode
{
    struct bstnode *lc;
    int data;
    struct bstnode *rc;
};

typedef struct bstnode *bstptr;
bstptr T;

void insert(bstptr &T, int k)
{
    if (T == NULL)
    {
        T = new (bstnode);
        T->data = k;
        T->rc = NULL;
        T->lc = NULL;
    }
    else
    {
        if (T->data > k)
        {
            insert(T->lc, k);
        }
        else
            insert(T->rc, k);
    }
}

// linked list
struct node
{
    int data;
    struct node *next;
};

typedef struct node *lptr;

lptr l;

void addfirst(lptr &l, int k)
{
    l = new (node);
    l->data = k;
    l->next = NULL;
}

void linsert(lptr l, int k)
{
    while (l->next != NULL)
    {
        l = l->next;
    }
    lptr r;
    r = new (node);
    r->data = k;
    r->next = NULL;
    l->next = r;
}

// creating a bst
void createBST()
{
    T = NULL;
    while (l != NULL)
    {
        insert(T, l->data);
        l = l->next;
    }
}

void displayNodes()
{
    // queue
    bstptr temp = new (bstnode);
    temp = T;
    queue<bstnode *> q;
    if (T == NULL)
        return;
    else
    {
        q.push(T);
        while (!q.empty())
        {
            T = q.front();
            cout << T->data << " ";
            if (T->lc != NULL)
                q.push(T->lc);
            if (T->rc != NULL)
                q.push(T->rc);
            q.pop();
        }
        cout << endl;
    }
    T = temp;
}

void Countchildern(bstptr T, int child[])
{
    bstptr temp = new (bstnode);
    temp = T;
    int i = 0;
    // queue
    queue<bstnode *> q;
    q.push(T);
    while (!q.empty())
    {
        int count = 0;
        T = q.front();
        q.pop();
        if (T->lc != NULL)
            count++, q.push(T->lc);
        if (T->rc != NULL)
            count++, q.push(T->rc);
        child[i] = count;
        i++;
    }
    T = temp;
}

void countsibling(bstptr T, int sibling[])
{
    bstptr temp = new (bstnode);
    temp = T;
    int i = 0;
    sibling[i] = 0; // root node has zero siblings
    i++;
    // queue
    queue<bstptr> q;
    q.push(T);
    while (!q.empty())
    {
        int a = 0, b = 0;
        T = q.front();
        q.pop();
        if (T->lc != NULL)
            a++, q.push(T->lc);
        if (T->rc != NULL)
            b++, q.push(T->rc);

        if (a && b)
        { // two nodes are present
            sibling[i] = 1;
            sibling[i + 1] = 1;
            i += 2;
        }
        else if (a || b)
        {
            sibling[i] = 0;
            i++;
        }
    }
    T = temp;
}

int main()
{
    l = NULL;
    int x, k = 0;
    cout << "Enter the values -Enter -1 to stop " << endl;
    cin >> x;
    k++;
    while (x != -1)
    {
        if (l == NULL)
            addfirst(l, x);
        else
            linsert(l, x);
        cin >> x;
        k++;
    }
    createBST();

    cout << "Level order traversal : " << endl;
    displayNodes();

    cout << "Childern of each node : " << endl;
    int child[100];

    Countchildern(T, child);
    for (int i = 0; i < k - 1; i++)
    {
        cout << child[i] << " ";
    }

    cout << endl;
    int Siblings[100];

    cout << "Siblings of each node : " << endl;
    countsibling(T, Siblings);

    for (int i = 0; i < k - 1; i++)
    {
        cout << Siblings[i] << " ";
    }
    cout << endl;
}