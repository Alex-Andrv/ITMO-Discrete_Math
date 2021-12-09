#include <bits/stdc++.h>

using namespace std;

void gen(vector<char> &ans, vector<vector<long long>> &dp, long long n, long long k, long long pos, long long bal)
{
    //cout << pos << " " << bal << endl;
    if (pos == 2 * n && bal == 0)
    {
        for (long long i = 1; i <= 2 * n; i++)
            cout << ans[i];
            return;
    }
    if (pos == 2 * n)
        return;
    if (bal == 0)
    {
        ans.push_back('(');
        gen(ans, dp, n, k, pos + 1, bal + 1);
        return;
    }
    if (bal == n)
    {
        ans.push_back(')');
        gen(ans, dp, n, k, pos + 1, bal - 1);
        return;
    }
    if (k >= dp[pos + 1][bal + 1])
    {
        k -= dp[pos + 1][bal + 1];
        ans.push_back(')');
        gen(ans, dp, n, k, pos + 1, bal - 1);
        return;
    }
    else
    {
        ans.push_back('(');
        gen(ans, dp, n, k, pos + 1, bal + 1);
        return;
    }
}

int main()
{
    freopen ("num2brackets.in","r",stdin);
    freopen ("num2brackets.out","w",stdout);
    long long n, k;
    cin >> n >> k;
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
    vector<char> ans;
    ans.push_back('#');
    gen(ans, dp, n, k, 0, 0);
    fclose (stdout);
    fclose (stdin);
}

