#include <bits/stdc++.h>

using namespace std;

int mod = (int)(1e9 + 7);


void dfs(int start, vector<vector<int>> &in, vector<bool> &useful)
{
    useful[start] = true;
    for (auto el : in[start])
    {
        if (!useful[el])
            dfs(el, in, useful);
    }
}

bool is_loop(int start, vector<vector<int>> &out, vector<int> &use, vector<bool> &useful, vector<int> & topol)
{
    use[start] = 1;
    bool loop = false;
    for (auto el : out[start])
    {
        if (use[el] == 0)
            loop |= is_loop(el, out, use, useful, topol);
        else
        {
            if (use[el] == 1 && useful[el])
                loop = true;
        }
    }
    use[start] = 2;
    if (useful[start])
        topol.push_back(start);
    return loop;
}

int ans(vector<vector<int>> &in, vector<int> &topol, vector<bool> &T)
{
    reverse(topol.begin(), topol.end());
    int res = 0;
    vector<int> ans(in.size());
    ans[0] = 1;
    for (int i = 0; i < topol.size(); i++)
        for (auto node : in[topol[i]])
            ans[topol[i]] = (ans[topol[i]] + ans[node]) % mod;
    for (int i = 0; i < T.size(); i++)
        if (T[i])
            res = (res + ans[i]) % mod;
    return res;
}

int main() {
    freopen("problem3.in", "r", stdin);
    freopen("problem3.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> T(n);
    for (int i = 0; i < k; i++)
    {
        int ind;
        cin >> ind;
        T[ind - 1] = true;
    }
    vector<vector<int>> in(n);
    vector<vector<int>> out(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        out[--a].push_back(--b);
        in[b].push_back(a);
    }
    vector<bool> useful(n);
    for (int i = 0; i < n; i++)
        if (T[i])
            dfs(i, in, useful);
    vector<int> use(n);
    vector<int> topol;
    cout << (is_loop(0, out, use, useful, topol) ? -1 : ans(in, topol, T));
}
