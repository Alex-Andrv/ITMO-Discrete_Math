#include <bits/stdc++.h>

using namespace std;

const int sm = 1;

void get_ans(vector<vector<long long>> &dp, vector<char> &ans, int pos, int bal, int n, long long k, stack<char> &last)
{
    //cout << pos << " " << bal << " " << k << " " << n << " " << dp[bal + sm + 1][2 * n - pos - 1] << endl;
    if (pos == 2 * n)
    {
        for (int i = 0; i < 2 * n; i++)
            cout << ans[i];
        return;
    }
    if (last.empty() || last.top() != '(')
    {
        if (k >= 2 * dp[bal + sm + 1][2 * n - pos - 1] && !last.empty() && last.top() == '[')
        {
            ans.push_back(']');
            last.pop();
            k -= (2 * dp[bal + sm + 1][2 * n - pos - 1]);
            get_ans(dp, ans, pos + 1, bal - 1, n, k, last);
            return;
        }
    }
    if (k >= dp[bal + sm + 1][2 * n - pos - 1] + (!last.empty() && last.top() == '(') * dp[bal + sm - 1][2 * n - pos - 1] && bal < n)
    {
        k -= (dp[bal + sm + 1][2 * n - pos - 1] + (!last.empty() && last.top() == '(') * dp[bal + sm - 1][2 * n - pos - 1]);
        ans.push_back('[');
        last.push('[');
        get_ans(dp, ans, pos + 1, bal + 1, n, k, last);
        return;
    }
    if (k >= 2 * dp[bal + sm + 1][2 * n - pos - 1] && !last.empty() && last.top() == '[')
    {
        ans.push_back(']');
        last.pop();
        k -= (2 * dp[bal + sm + 1][2 * n - pos - 1]);
        get_ans(dp, ans, pos + 1, bal - 1, n, k, last);
        return;
    }
    if (k >= dp[bal + sm + 1][2 * n - pos - 1] && !last.empty() && last.top() == '(')
    {
        ans.push_back(')');
        last.pop();
        k -= dp[bal + sm + 1][2 * n - pos - 1];
        get_ans(dp, ans, pos + 1, bal - 1, n, k, last);
        return;
    }
    ans.push_back('(');
    last.push('(');
    get_ans(dp, ans, pos + 1, bal + 1, n, k, last);
    return;
}

int main()
{
    freopen ("num2brackets2.in","r",stdin);
    freopen ("num2brackets2.out","w",stdout);
    int n;
    long long k;
    cin >> n >> k;
    vector<vector<long long>> dp(n + 3, vector<long long> (2 * n + 1));
    dp[0 + sm][0] = 1;
    for (int j = 1; j < 2 * n + 1; j++)
        for (int i = 0; i <= n; i++)
            dp[i + sm][j] = dp[i + sm - 1][j - 1] + 2 * dp[i + sm + 1][j - 1];
    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
            cout << dp[i + sm][j] << " ";
        cout << endl;
    }*/
    vector<char> ans;
    stack<char> last;
    get_ans(dp, ans, 0, 0, n, k, last);
    fclose (stdout);
    fclose (stdin);
}

