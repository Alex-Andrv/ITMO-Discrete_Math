
#include <bits/stdc++.h>

using namespace std;

int gen(vector<long long > &a, long long  n, long long  k, long long  pos, vector<vector<long long> > &fac, vector<bool> &visi, int pred)
{
    if (k == pos)
    {
        return 0;
    }
    int m = 0;
    for (long long  i = pred + 1; i < a[pos]; i++)
    {
         //  cout << i << " " << k << " " << pos << " " << fac[n - i][k - pos - 1] << endl;
        if (!visi[i])
        {
            m = m + fac[n - i][k - pos - 1];
        }
    }
        // cout << m << endl;
    visi[a[pos]] = true;
    return m + gen(a, n, k, pos + 1, fac, visi, a[pos]);
}


int  main()
{
    //freopen ("choose2num.in","r",stdin);
    //freopen ("choose2num.out","w",stdout);
    long long  n, k;
    cin >> n >> k;
    vector<bool> visi(n);
    vector<vector<long long>> C(n + 1, vector<long long> (k + 1));
    for (int i = 0; i < n + 1; i++)
        C[i][0] = 1;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < k + 1; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    vector<long long > ans(k);
    for (int i = 0; i < k; i++)
        cin >> ans[i];
    cout << gen(ans, n, k, 0, C, visi, 0);
    //fclose (stdout);
    //fclose (stdin);
}
