
#include <bits/stdc++.h>

using namespace std;

long long ans(vector<long long > &a, long long  n, long long pos, vector<long long > &fac, vector<bool> &visi)
{
    if (n == pos)
    {
        return 0;
    }
    long long k = 0;
    for (long long i = 1; i < a[pos]; i++)
    {
        if (!visi[i])
        {
           k += fac[n - pos - 1];
        }
    }
    //cout << k << endl;
    visi[a[pos]] = true;
    return k + ans(a, n, pos + 1, fac, visi);
}


int  main()
{
    freopen ("perm2num.in","r",stdin);
    freopen ("perm2num.out","w",stdout);
    long long  n, k;
    cin >> n;
    vector<bool> visi(n + 1);
    vector<long long > fac(n + 1);
    fac[0] = 1;
    for (long long  i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i;
    vector<long long > a(n + 1);
    for (long long  i = 0; i < n; i++)
        cin >> a[i];
    cout << ans(a, n, 0, fac, visi);
    fclose (stdout);
    fclose (stdin);
}
