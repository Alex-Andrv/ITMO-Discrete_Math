#include <bits/stdc++.h>

using namespace std;

const int sm = 1;

long long get_ans(vector<vector<long long>> &dp, vector<char> &ans, int pos, int bal, int n, stack<char> &last)
{
    //cout << pos << " " << bal << " " << k << " " << n << " " << dp[bal + sm + 1][2 * n - pos - 1] << endl;
    if (pos == 2 * n)
    {
        return 0;
    }
    long long k = 0;
    switch (ans[pos])
    {
    case '(':
        last.push('(');
        bal++;
        break;
    case ')':
        last.pop();
        k += dp[bal + sm + 1][2 * n - pos - 1];
        bal--;
        break;
    case '[':
        if (!last.empty() && last.top() == '(')
                k += dp[bal + sm - 1][2 * n - pos - 1];
        last.push('[');
        k += dp[bal + sm + 1][2 * n - pos - 1];
        bal++;
        break;
    case ']':
        last.pop();
        k += (2 * dp[bal + sm + 1][2 * n - pos - 1]);
        bal--;
        break;
    }
    return k + get_ans(dp, ans, pos + 1, bal, n, last);
}

int main()
{
    freopen ("brackets2num2.in","r",stdin);
    freopen ("brackets2num2.out","w",stdout);
    vector<char> ans;
    char c;
    int n = 0;
    while (cin >> c)
    {
        ans.push_back(c);
        n++;
    }
    n /= 2;
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
    stack<char> last;
    cout << get_ans(dp, ans, 0, 0, n, last);
    fclose (stdout);
    fclose (stdin);
}

