
#include <bits/stdc++.h>

using namespace std;

void gen(vector<long long > &a, long long  n, long long  k, int m, long long  pos, vector<vector<long long> > &fac, vector<bool> &visi, int pred)
{
   // cout << m << endl;
    if (k == pos)
    {
        for (long long  i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (long long  i = pred + 1; i <= n; i++)
    {
     //   cout << i << " " << k << " " << pos << " " << fac[n - i][k - pos - 1] << endl;
        if (!visi[i] && n - i >= k - pos - 1)
        {
            if (m >= fac[n - i][k - pos - 1])
                m = m - fac[n - i][k - pos - 1];
            else
            {
                visi[i] = true;
                a[pos] = i;
                gen(a, n, k, m, pos + 1, fac, visi, i);
                return;
            }
        }
    }
}


int  main()
{
    freopen ("num2choose.in","r",stdin);
    freopen ("num2choose.out","w",stdout);
    long long  n, k, m;
    cin >> n >> k >> m;
    vector<bool> visi(n);
    vector<vector<long long>> fac(n + 1, vector<long long> (k + 1));
    for (int i = 0; i < n + 1; i++)
        fac[i][0] = 1;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < k + 1; j++)
            fac[i][j] = fac[i - 1][j] + fac[i - 1][j - 1];
    vector<long long > ans(k);
    gen(ans, n, k, m, 0, fac, visi, 0);
    fclose (stdout);
    fclose (stdin);
}
