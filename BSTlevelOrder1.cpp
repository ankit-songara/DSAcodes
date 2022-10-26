#include <iostream>
#include <queue>
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

void levelOrder(BSTPTR T)
{
    queue<BSTPTR> q;
    q.push(T);
    q.push(nullptr);
    while (!q.empty())
    {
        T = q.front();
        q.pop();
        cout << T->data << " ";

        if (T->lc != NULL)
        {
            q.push(T->lc);
        }

        if (T->rc != NULL)
        {
            q.push(T->rc);
        }

        if (q.front() == nullptr)
        {
            q.pop();
            cout <<endl;
            if (q.empty())
                break;
            q.push(nullptr);
        }
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
    levelOrder(T2);
}