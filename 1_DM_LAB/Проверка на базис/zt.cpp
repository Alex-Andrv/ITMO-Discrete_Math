#include <bits/stdc++.h>

using namespace std;

bool check(int f, int s)
{
    return (s & ~f) == 0 ? 1: 0;
}

bool checkL(int zn, int s)
{
    if (zn == 0)
        return false;
    for (int i = 1; i < 1 << s; i *= 2)
        if (zn == i)
            return false;
    return true;
}

bool F0(string &st, int s)
{
    return st[0] != '0';
}

bool F1(string &st, int s)
{
    return st[(1 << s) - 1] != '1';
}

bool M(string &st, int s)
{
    for (int i = 0; i < 1 << s; i++)
    {
        for (int j = i; j >= 0; j--)
            if (check(i, j) && st[i] < st[j])
                return true;
    }
    return false;
}

bool S(string &st, int s)
{
    for (int i = 0; i < 1 << s; i++)
    {
        if (st[i] == st[(1 << s) - i - 1])
            return true;
    }
    return false;
}

bool L(string &st, int s)
{
    for (int i = 0; i < 1 << s; i++)
    {
        int ax = 0;
        for (int j = i; j >= 0; j--)
        {
            if (check(i, j))
            {
                ax = ax ^ (st[j] - '0');
            }
        }
        if (ax && checkL(i, s))
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<bool> ans(5, false);
    string st;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        cin >> st;
        if (F0(st, s))
        {
            //cout << "F0 ";
            ans[0] = true;
        }
        if (F1(st, s))
        {
            //cout << "F1 ";
            ans[1] = true;
        }
        if (M(st, s))
        {
            //cout << "M ";
            ans[2] = true;
        }
        if (S(st, s))
        {
            //cout << "S ";
            ans[3] = true;
        }
        if (L(st, s))
        {
            //cout << "L ";
            ans[4] = true;
        }
        //cout << endl;
    }
    for (int i = 0; i < 5; i++)
        if (!ans[i])
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}
