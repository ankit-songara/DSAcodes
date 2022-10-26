#include <iostream>
#include <stack>
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

void reverseLevelorder(BSTPTR T)
{
    queue<BSTPTR> q;
    stack<BSTPTR> s;
    q.push(T);
    s.push(T);
    q.push(nullptr);
    s.push(nullptr);
    while (!q.empty())
    {
        T = q.front();
        q.pop();
        if (T->rc != NULL)
        {
            q.push(T->rc);
            s.push(T->rc);
        }

        if (T->lc != NULL)
        {
            q.push(T->lc);
            s.push(T->lc);
        }

        if (q.front() == nullptr)
        {
            s.push(nullptr);
            q.pop();
            if (q.empty())
                break;
            q.push(nullptr);
        }
    }

    while (!s.empty())
    {
        if (s.top() == nullptr)
        {
            s.pop();
        }
        else
        {
            cout << s.top()->data << " ";
            s.pop();
        }
    }
}

void squirrelLevelorder(BSTPTR T)
{
    queue<BSTPTR> q;
    stack<BSTPTR> s;
    int l = 0;
    q.push(T);
    q.push(nullptr);
    while (1)
    {
        T = q.front();
        q.pop();
        if (T == nullptr)
        {
            if (l % 2 != 0)
            {
                while (!s.empty())
                {
                    cout << s.top()->data << " ";
                    s.pop();
                }
            }
            q.push(nullptr);
            l++;
        }
        else
        {
            if (l % 2 == 0)
            {
                cout << T->data << " ";
            }
            if (l % 2 != 0)
            {
                s.push(T);
            }
            if (T->lc != NULL)
            {
                q.push(T->lc);
            }

            if (T->rc != NULL)
            {
                q.push(T->rc);
            }
        }
    }
}

void reverseSquirrelOrder(BSTPTR T)
{
    queue<BSTPTR> q;
    stack<BSTPTR> s;
    int l = 0;
    q.push(T);
    q.push(nullptr);
    while (1)
    {
        T = q.front();
        q.pop();
        if (T == nullptr)
        {
            if (l % 2 == 0)
            {
                while (!s.empty())
                {
                    cout << s.top()->data << " ";
                    s.pop();
                }
            }
            q.push(nullptr);
            l++;
        }
        else
        {
            if (l % 2 != 0)
            {
                cout<<T->data<<" ";
            }
            if (l % 2 == 0)
            {
                s.push(T);
            }
            if (T->lc != NULL)
            {
                q.push(T->lc);
            }

            if (T->rc != NULL)
            {
                q.push(T->rc);
            }
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
    reverseSquirrelOrder(T2);
}