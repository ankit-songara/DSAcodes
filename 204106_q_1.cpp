#include <iostream>
#include <queue>
using namespace std;

void checkPq(string &s)
{
    queue<char> pq;
    for (int i = 0; i < (s.size()) / 2; i++)
    {
        pq.push(s[i]);
    }
    bool flag = true;
    for (int i = s.size() / 2; i < s.size(); i++)
    {
        char c = pq.front();
        pq.pop();
        if (c == s[i])
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag == true)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
}

int main()
{
    queue<char> pq;
    string s;
    cin >> s;
    checkPq(s);
}