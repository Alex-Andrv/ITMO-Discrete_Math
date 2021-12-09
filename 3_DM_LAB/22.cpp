#include <bits/stdc++.h>

using namespace std;


int get_ans(vector<vector<int>> &dp, vector<int> &ans, int pos, int pred, int n)
{
    //cout <<  << endl;
    if (pos == ans.size())
    {
        return 0;
    }
    int i = pred;
    int m = 0;
   // cout << dp[ch - i][k] << " " << i << endl;
    while (i != ans[pos])
    {
        m += dp[n - i][i];
        i++;
    }
   // cout << m << endl;
    return m +  get_ans(dp, ans, pos + 1, i, n - i);
}

int gen(vector<vector<int>> &dp, int ch, int k, int n)
{
    if (k > n)
        return 0;
    if (ch == 0)
    {
        dp[ch][k] = 1;
        return dp[ch][k];
    }
    if (ch != 0 && k > ch)
    {
        dp[ch][k] = 0;
        return dp[ch][k];
    }
    if (dp[ch][k] != 0)
    {
        return dp[ch][k];
    }
    dp[ch][k] = gen(dp, ch - k, k, n) + gen(dp, ch, k + 1, n);
    return dp[ch][k];
}

int main()
{
    //freopen ("part2num.in","r",stdin);
    //freopen ("part2num.out","w",stdout);
    int n = 0;
    vector<int> ans;
    char c;
    int b;
    cin >> b;
    n += b;
    ans.push_back(b);
    while (cin >> c)
    {
        cin >> b;
        ans.push_back(b);
        n += b;
    }
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    gen(dp, n, 1, n);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << get_ans(dp, ans, 0, 1, n);
   // fclose (stdout);
    //fclose (stdin);
}


