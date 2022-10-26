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

void leftmostPath(BSTPTR T)
{
    int i;
    BSTPTR temp = NULL;
    if (T == NULL)
    {
        return;
    }
    queue<BSTPTR> q;
    q.push(T);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            temp = q.front();
            q.pop();
            if (i == 1)
            {
                cout << temp->data << " ";
            }

            if (temp->lc != NULL)
            {
                q.push(temp->lc);
            }

            if (temp->rc != NULL)
            {
                q.push(temp->rc);
            }
        }
    }
}

void rightmostPath(BSTPTR T)
{
    int i;
    BSTPTR temp = NULL;
    if (T == NULL)
    {
        return;
    }
    queue<BSTPTR> q;
    q.push(T);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            temp = q.front();
            q.pop();
            if (i == 1)
            {
                cout << temp->data << " ";
            }

            if (temp->rc != NULL)
            {
                q.push(temp->rc);
            }
        }
    }
}

int arr[50];
int maxSum(BSTPTR T)
{

    if (T == NULL)
    {
        return 0;
    }
    int sum = T->data;
    int ls = 0;
    int rs = 0;

    if (T->lc == NULL && T->rc == NULL)
    {
        return sum;
    }

    if (T->rc != NULL)
    {
        rs = maxSum(T->rc);
    }

    if (T->lc != NULL)
    {
        ls = maxSum(T->lc);
    }

    if (rs > ls)
    {
        sum += rs;
    }
    else
    {
        sum += ls;
    }

    return sum;
}

void maxSumPath(BSTPTR T, int i, int sum, int Max)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        sum = sum + T->data;
        arr[i] = T->data;
        i++;

        if (sum == Max)
        {
            for (int j = 0; j < i; j++)
            {
                cout << arr[j] << " ";
            }
        }

        if (T->rc != NULL)
        {
            maxSumPath(T->rc, i, sum, Max);
        }

        if (T->lc != NULL)
        {
            maxSumPath(T->lc, i, sum, Max);
        }
    }
}

int Arr[50];
int minSum(BSTPTR T)
{
    if (T == NULL)
        return 0;
    int sum = T->data;
    int leftSum = 1e+5;
    int rightSum = 1e+5;
    if (T->lc == NULL && T->rc == NULL)
    {
        return sum;
    }
    else
    {

        if (T->lc != NULL)
        {
            leftSum = minSum(T->lc);
        }
        if (T->rc != NULL)
        {
            rightSum = minSum(T->rc);
        }
        if (leftSum < rightSum)
        {
            sum += leftSum;
        }
        else
        {
            sum += rightSum;
        }
    }
    return sum;
}

void minSumPath(BSTPTR T, int i, int sum, int Min)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        sum = sum + T->data;
        Arr[i] = T->data;
        i++;

        if (sum == Min)
        {
            for (int j = 0; j < i; j++)
            {
                cout << Arr[j] << " ";
            }
        }

        if (T->lc != NULL)
        {
            minSumPath(T->lc, i, sum, Min);
        }

        if (T->rc != NULL)
        {
            minSumPath(T->rc, i, sum, Min);
        }
    }
}

int MaxEven(BSTPTR T)
{
    if (T == NULL)
    {
        return 0;
    }

    int count = 0;

    if (T->data % 2 == 0)
    {
        count++;
    }

    int ls = MaxEven(T->lc);
    int rs = MaxEven(T->rc);
    count += max(ls, rs);
    return count;
}

void PathMaxEven(BSTPTR T, int i, int k, int count)
{
    if (T == NULL)
    {
        return;
    }
    arr[i] = T->data;
    if (T->data % 2 == 0)
    {
        k++;
    }
    i++;

    if (T->lc != NULL)
    {
        PathMaxEven(T->lc, i, k, count);
    }

    if (T->rc != NULL)
    {
        PathMaxEven(T->rc, i, k, count);
    }

    if (T->lc == NULL && T->rc == NULL)
    {
        if (k == count)
        {
            for (int j = 0; j < i; j++)
            {
                cout << arr[j] << " ";
            }
        }
    }
}

int MaxOdd(BSTPTR T)
{
    if (T == NULL)
    {
        return 0;
    }

    int count = 0;

    if (T->data % 2 != 0)
    {
        count++;
    }

    int ls = MaxOdd(T->lc);
    int rs = MaxOdd(T->rc);
    count += max(ls, rs);
    return count;
}

void PathMaxOdd(BSTPTR T, int i, int k, int count)
{
    if (T == NULL)
    {
        return;
    }
    arr[i] = T->data;
    if (T->data % 2 != 0)
    {
        k++;
    }
    i++;

    if (T->lc != NULL)
    {
        PathMaxOdd(T->lc, i, k, count);
    }

    if (T->rc != NULL)
    {
        PathMaxOdd(T->rc, i, k, count);
    }

    if (T->lc == NULL && T->rc == NULL)
    {
        if (k == count)
        {
            for (int j = 0; j < i; j++)
            {
                cout << arr[j] << " ";
            }
        }
    }
}

int main()
{
    BSTPTR T2;
    T2 = NULL;
    int n, count,count1;
    while (n != -1)
    {
        cin >> n;
        if (n == -1)
            break;
        insert(T2, n);
    }
    leftmostPath(T2);
    cout<<endl;
    rightmostPath(T2);
    cout<<endl;
    int a=maxSum(T2);
    maxSumPath(T2,0,0,a);
    cout<<endl;
    int b=minSum(T2);
    minSumPath(T2,0,0,b);
    cout<<endl;
    maxSumPath(T2,0,0,22);
    cout<<endl;
    count=MaxEven(T2);
    PathMaxEven(T2,0,0,count);
    cout<<endl;
    count1 = MaxOdd(T2);
    PathMaxOdd(T2, 0, 0, count1);
}
