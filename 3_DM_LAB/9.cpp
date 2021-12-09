

#include <bits/stdc++.h>

using namespace std;

void gen(vector<char> a, int n, int pos, int bal)
{
   // cout << n << " " << pos << " " << bal << endl;
    if (pos == 2 * n)
    {
        for (int i = 0; i < 2 * n; i++)
            cout << a[i];
        cout << endl;
        return;
    }
    if (bal == 0)
    {
        a[pos] = '(';
        gen(a, n, pos + 1, bal + 1);
    }
    if (bal == 2 * n - pos)
    {
        a[pos] = ')';
        gen(a, n, pos + 1, bal - 1);
    }
    if (bal != 0 && bal != 2 * n - pos)
    {
        a[pos] = '(';
        gen(a, n, pos + 1, bal + 1);
        a[pos] = ')';
        gen(a, n, pos + 1, bal - 1);
    }
}

int main()
{
    freopen ("brackets.in","r",stdin);
    freopen ("brackets.out","w",stdout);
    int n;
    cin >> n;
    vector<char> pref(n * 2);
    gen(pref, n, 0, 0);
    fclose (stdout);
    fclose (stdin);
}
