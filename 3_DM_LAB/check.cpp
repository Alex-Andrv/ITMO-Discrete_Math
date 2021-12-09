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
    return m + get_ans(dp, ans, pos + 1, i, n - i);
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

int main2( vector<int> &ans, int n)
{
    //freopen ("part2num.in","r",stdin);
    //freopen ("part2num.out","w",stdout);
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    gen(dp, n, 1, n);
    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    return get_ans(dp, ans, 0, 1, n);
    //fclose (stdout);
    //fclose (stdin);
}


void get_ans1(vector<vector<int>> &dp, vector<int> &ans, int ch, int k, int n, int m)
{
   // cout << ch << " " << k << " " << m << endl;
    if (ch == 0)
    {
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
    get_ans1(dp, ans, ch - i, i, n, m);
}

bool main1(int n, int k)
{
    //freopen ("num2part.in","r",stdin);
    //freopen ("num2part.out","w",stdout);
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    gen(dp, n, 1, n);
    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    vector<int> ans;
    get_ans1(dp, ans, n, 1, n, k);
    return k == main2(ans, n);
    //fclose (stdout);
    //fclose (stdin);
}




int main()
{
    srand(time(NULL));
    int n = 91;
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    gen(dp, n, 1, n);
    int k =  dp[n][1] - 1;
    while(k > 0)
    {
        if (k % 10000 == 0)cout << n << " " << k <<" " << dp[n][1]<< endl;
        if (!main1(n, k))
            {cout << n << " " << k << " " << dp[n][1];
            char c;
            cin >> c;}
        k--;
    }
}
