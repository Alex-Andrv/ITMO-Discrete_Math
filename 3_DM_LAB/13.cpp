
#include <bits/stdc++.h>

using namespace std;

void gen(vector<long long > &a, long long  n, long long  k, long long  pos, vector<long long > &fac, vector<bool> &visi)
{
    if (n == pos)
    {
        for (long long  i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        return;
    }
    for (long long  i = 1; i <= n; i++)
    {
        if (!visi[i])
        {
           // cout << k << " " <<fac[n - pos - 1] << endl;
            if (k >= fac[n - pos - 1])
                k -= fac[n - pos - 1];
            else
            {
                visi[i] = true;
                a[pos] = i;
                gen(a, n, k, pos + 1, fac, visi);
            }
        }
    }
}


int  main()
{
    freopen ("num2perm.in","r",stdin);
    freopen ("num2perm.out","w",stdout);
    long long  n, k;
    cin >> n >> k;
    vector<bool> visi(n);
    vector<long long > fac(n + 1);
    fac[0] = 1;
    for (long long  i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i;
    vector<long long > ans(n);
    gen(ans, n, k, 0, fac, visi);
    fclose (stdout);
    fclose (stdin);
}
