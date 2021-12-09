#include <bits/stdc++.h>

using namespace std;


bool next(vector<int> &ans, int n, int k)
{
    ans.push_back(n + 1);
    for (int i = k - 1; i > -1; i--)
    {
        if (ans[i + 1] - ans[i] > 1)
        {
            ans[i]++;
            for (int j = i + 1; j < k; j++)
                ans[j] = ans[j - 1] + 1;
            return true;
        }
    }
    if (ans[0] < n - k + 1)
    {
        ans[0]++;
        for (int j = 1; j < k; j++)
                ans[j] = ans[j - 1] + 1;
        return true;
    }
    return false;
}

int main()
{
    freopen ("nextchoose.in","r",stdin);
    freopen ("nextchoose.out","w",stdout);
    int n, k;
    cin >> n >> k;
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
        cin >> ans[i];
    sort(ans.begin(), ans.end());
    if (!next(ans, n, k))
    {
        cout << "-1";
    }
    else
    {
        for (int j = 0; j < k; j++)
            cout << ans[j] << " ";
        cout << endl;
    }
    fclose (stdout);
    fclose (stdin);
}





