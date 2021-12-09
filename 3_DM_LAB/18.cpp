#include <bits/stdc++.h>

using namespace std;

long long gen(vector<char> &ans, vector<vector<long long>> &dp, long long n, long long pos, long long bal)
{
    if (pos == 2 * n && bal == 0)
    {
        return 0;
    }
    if (bal == 0)
    {
        return gen(ans, dp, n, pos + 1, bal + 1);
    }
    if (bal == n)
    {
        return gen(ans, dp, n, pos + 1, bal - 1);
    }
    if (ans[pos] == ')' )
    {
        return gen(ans, dp, n, pos + 1, bal - 1) + dp[pos + 1][bal + 1];
    }
    else
    {
        return gen(ans, dp, n, pos + 1, bal + 1);
    }
}

int main()
{
    freopen ("brackets2num.in","r",stdin);
    freopen ("brackets2num.out","w",stdout);
    long long n = 0;
    vector<char> ans;
    char b;
    while (cin >> b)
    {
        ans.push_back(b);
        if (b == '(')
            n++;
    }
    vector<vector<long long>> dp(2 * n + 1, vector<long long> (n + 1));
    dp[2 * n][0] = 1;
    // dp[i][j] = dp[i - 1][j - 1] + d[i - 1][j + 1];
    for (long long i = 2 * n - 1; i >= 0; i--)
        for (long long j = 0; j <= n; j++)
        {
            if (j != 0 && j != n)
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j - 1];
            if (j == 0)
                dp[i][j] = dp[i + 1][j + 1];
            if (j == n)
                dp[i][j] = dp[i + 1][j - 1];
        }
    /*for (long long i = 0; i <=2 * n;i++ )
    {
        for (long long j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    cout << gen(ans, dp, n, 0, 0);
    fclose (stdout);
    fclose (stdin);
}
