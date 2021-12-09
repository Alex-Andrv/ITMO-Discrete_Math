#include <bits/stdc++.h>

using namespace std;

void gen(vector<int> a, int n, int pos, int pred)
{
    if (pos == n)
    {
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << endl;
        return;
    }
    if (pred == 0)
    {
        a[pos] = 0;
        gen(a, n, pos + 1, 0);
        a[pos] = 1;
        gen(a, n, pos + 1, 1);
    }
    else
    {
        a[pos] = 0;
        gen(a, n, pos + 1, 0);
    }

}

int main()
{
    freopen ("vectors.in","r",stdin);
    freopen ("vectors.out","w",stdout);
    int n;
    cin >> n;
    int a[n + 2];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n + 1; i++)
        a[i] = a[i - 1] + a[i - 2];
    cout << a[n + 1] << endl;
    vector<int> pref(n);
    gen(pref, n, 0, 0);
    fclose (stdout);
    fclose (stdin);
}
