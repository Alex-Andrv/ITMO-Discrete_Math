#include <bits/stdc++.h>

using namespace std;


void dfs(int start, vector<vector<vector<int>>> &in, vector<bool> &useful)
{
    useful[start] = true;
    for (auto v : in[start])
    {
        for (auto el : v)
        if ( el != -1 && !useful[el])
            dfs(el, in, useful);
    }
}

void dfs2(int start, vector<vector<int>> &in, vector<bool> &useful)
{
    useful[start] = true;
    for (auto el : in[start])
    {
            if ( el != -1 && !useful[el])
                dfs2(el, in, useful);
    }
}

void min_dka(vector<vector<vector<int>>> &in, vector<vector<int>> &out, vector<bool> &T, int &n, int &m, int &k)
{
    vector<vector<bool>> mark(n, vector<bool> (n, false));
    vector<bool> visi(n);
    for (int i = 0; i < n; i++)
        if (T[i])
        dfs(i, in, visi);
    vector<bool> visi2(n);
    dfs2(0, out, visi2);
    queue<pair<int, int>> q;
    for (int  i = 0; i < n; i++)
    {
        if (!visi[i] || !visi2[i])
        {
            for (int j = 0; j < n; j++)
            {
                q.push({i, j});
                q.push({j, i});
                mark[i][j] = true;
                mark[j][i] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (!mark[i][j] && T[i] != T[j])
            {
                q.push({i, j});
                mark[i][j] = mark[j][i] = true;
            }
        }
    while (!q.empty())
    {
        pair<int, int> f = q.front();
        int u = f.first;
        int v = f.second;
        q.pop();
        if (u == v)
            continue;
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (auto r : in[u][c - 'a'])
                for (auto s : in[v][c - 'a'])
                {
                    if (!mark[r][s])
                    {
                        mark[r][s] = mark[s][r] = true;
                        q.push({r, s});
                    }
                }
        }
    }
    vector<int> sss(n, -1);
    int next_s = 0;
    for (int i = 0; i < n; i++)
    {
        if (sss[i] == -1 && !mark[i][i]) {
            sss[i] = next_s;
            for (int j = 0; j < n; j++)
            {
                if (!mark[i][j])
                {
                    sss[j] = next_s;
                }
            }
            next_s++;
        }
    }
    set<int> used;
    vector<vector<int>> new_out(next_s, vector<int> (33, -1));
    vector<bool> new_T(next_s);
    int new_n = next_s, new_m = 0, new_k = 0;
    for (int i = 0; i < n; i++)
    {
        if (used.count(sss[i]) == 0 && sss[i] != -1) {
            if (T[i]) {
                new_T[sss[i]]= true;
                new_k++;
            }
            used.insert(sss[i]);
            for (int j = 0; j < n; j++)
            {
                if (!mark[i][j])
                {
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        for (auto el : in[j][c - 'a'])
                        {
                            if (sss[el] != -1 && new_out[sss[el]][c - 'a'] == -1)
                            {
                                new_out[sss[el]][c - 'a'] = sss[i];
                                new_m++;
                            }
                        }
                    }
                }
            }
        }
    }
    n = new_n;
    m = new_m;
    k = new_k;
    out = new_out;
    T = new_T;
}

int main()
{
    freopen("minimization.in", "r", stdin);
    freopen("minimization.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> T(n);
    for (int i = 0; i < k; i++)
    {
        int ind;
        cin >> ind;
        T[--ind] = true;
    }
    vector<vector<int>> out(n, vector<int> (33, -1));
    vector<vector<vector<int>>> in(n, vector<vector<int>> (33));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        out[--a][c - 'a'] = --b;
        in[b][c - 'a'].push_back(a);
    }
    min_dka(in, out, T, n, m, k);
    cout << n << " " << m << " " << k << endl;
    for (int i = 0; i < n; i++)
        if (T[i])
            cout << i + 1 << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (out[i][c - 'a'] != -1)
                cout << i + 1 << " " << out[i][c - 'a'] + 1 << " " << c << endl;
        }
}

