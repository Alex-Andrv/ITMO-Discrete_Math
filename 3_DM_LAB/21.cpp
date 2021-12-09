#include <bits/stdc++.h>

using namespace std;


void get_ans(vector<vector<int>> &dp, vector<int> &ans, int ch, int k, int n, int m)
{
   // cout << ch << " " << k << " " << m << endl;
    if (ch == 0)
    {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << "+" << ans[i];
        return;
    }
    int i = k;
   // cout << dp[ch - i][k] << " " << i << endl;
    while (m >= dp[ch - i][i])
    {
        m -= dp[ch - i][i];
        i++;
    }
    ans.push_back(i);
    get_ans(dp, ans, ch - i, i, n, m);
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
    //freopen ("num2part.in","r",stdin);
    //freopen ("num2part.out","w",stdout);
    int n;
    int k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    gen(dp, n, 1, n);
    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    vector<int> ans;
    get_ans(dp, ans, n, 1, n, k);
    //fclose (stdout);
    //fclose (stdin);
}


