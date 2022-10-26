#include <iostream>
using namespace std;
typedef struct bstnode
{
    int data;
    bstnode *lc;
    bstnode *rc;
} * bstptr;
bstptr z;
int arr[100][100];
void insert(bstptr &t, int k)
{
    if (t == NULL)
    {
        t = new bstnode();
        t->data = k;
        t->lc = NULL;
        t->rc = NULL;
    }
    else
    {
        if (k < t->data)
        {
            insert(t->lc, k);
        }
        else
        {
            insert(t->rc, k);
        }
    }
}
int height(bstptr t)
{
    if (t == NULL)
        return -1;
    return 1 + max(height(t->lc), height(t->rc));
}
int hod(bstptr t, int hd, int &minahd, int &maxahd)
{
    if (t == NULL)
        return 0;
    minahd = min(hd, minahd);
    maxahd = max(hd, maxahd);
    hod(t->lc, hd + 1, minahd, maxahd);
    hod(t->rc, hd - 1, minahd, maxahd);
}
void print(bstptr t, int row, int low, int high)
{
    if (high < low || t == NULL)
        return;
    int mid = (low + high) / 2;
    arr[row][mid] = t->data;
    print(t->lc, row + 1, low, mid);
    print(t->rc, row + 1, mid + 1, high);
}
int main()
{
    int k;
    cin >> k;
    while (1)
    {
        if (k == -1)
        {
            break;
        }
        insert(z, k);
        cin >> k;
    }
    int mina = 3371;
    int maxa = 0;
    hod(z, 0, mina, maxa);
    int row = height(z);
    int col = 4 * max(-1 * mina, maxa);
    for (int i = 0; i < row + 1; i++)
    {
        for (int j = 0; j < col + 1; j++)
        {
            arr[i][j] = 0;
        }
    }
    print(z, 0, 0, col);
    for (int i = 0; i < row + 1; i++)
    {
        for (int j = 0; j < col + 1; j++)
        {
            if (arr[i][j] == 0)
                cout << "* ";
            else
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
}