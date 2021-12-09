#include <bits/stdc++.h>

using namespace std;


bool next(vector<vector<int>> &ans, int n, int m)
{
    bool zn = false;
    vector<bool> used(n + 1, false);
    for (int i = (int)(ans.size()) - 1; i >= 0; i--)
    {
        //cout << i << " " << used[4] << endl;
        for (int j = ans[i].back() + 1; j < n + 1; j++)
        {
            if (used[j])
            {
                ans[i].push_back(j);
                used[j] = false;
                zn = true;
                break;
            }
        }
        if (zn)
            break;
        for (int j = (int)(ans[i].size()) - 1; j >= 0; j--)
        {
            if (j != 0)
                for (int k = ans[i][j] + 1; k < n + 1; k++)
                {
                    if (used[k])
                    {
                        used[ans[i][j]] = true;
                        ans[i][j] = k;
                        used[k] = false;
                        zn = true;
                        break;
                    }
                }
            if (zn)
                break;
            used[ans[i][j]] = true;
            ans[i].pop_back();
            if (ans[i].size() == 0)
                ans.pop_back();
        }
        if (zn)
            break;
    }
    for (int i = 1; i <= n; i++)
        if (used[i])
        {
            ans.push_back(vector<int>());
            ans[ans.size() - 1].push_back(i);
        }
    return zn;
}

int main()
{
    freopen ("nextsetpartition.in","r",stdin);
    freopen ("nextsetpartition.out","w",stdout);
    while (true)
    {
        //cout << "!!";
        int n, m;
        cin >> n >> m;
        if (n == m && n == 0)
            break;
        vector<vector<int>> ans(m);
        string st;
        getline(cin, st);
        for (int i = 0; i < m; i++)
        {
            getline(cin, st);
            istringstream scin(st);
            int b;
            while (scin >> b)
            {
                ans[i].push_back(b);
            }
        }
        if (!next(ans, n, m))
        {
            cout << n << " " << n << endl;
            for (int i = 1; i <= n; i++)
                cout << i << endl;
            continue;
        }
        cout << n << " " << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    fclose (stdout);
    fclose (stdin);
}







