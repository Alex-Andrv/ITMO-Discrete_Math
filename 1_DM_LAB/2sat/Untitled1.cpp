#include <bits/stdc++.h>

using namespace std;

void dfs(int i, vector<vector<int> > &g, vector<int> &visited, vector<int> &ans)
{   //cout << "<<" << i - 2<< ">>" << " ";
    visited[i] = 0;
    for (auto u: g[i])
        if (visited[u] == -1)
            dfs(u, g, visited, ans);
    ans.push_back(i);
    //cout << i - 2<< " ";

}

void dfs2(int i, vector<vector<int> > &gr, vector<int> &visited, int co)
{
    visited[i] = co;
    for (auto u: gr[i])
    {
        if (visited[u] == 0)
            dfs2(u, gr, visited, co);
    }
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int> > g(n * 2 + 1);
    vector<vector<int> > gr(n * 2 + 1);
    for (int i = 0; i < m; i++)
    {
        int f, s;
        cin >> f >> s;
        g[f * -1 + n].push_back(s + n);
        g[s * -1 + n].push_back(f + n);
        gr[s + n].push_back(f * -1 + n);
        gr[f + n].push_back(s * -1 + n);
    }
    vector<int> visited(n * 2 + 1, -1);
    vector<int> ans;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        if (visited[i] == -1 && i != n)
        {
            dfs(i, g, visited, ans);
        }
    }
    int co = 1;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (visited[ans[i]] == 0)
        {
            dfs2(ans[i], gr, visited, co);
            co++;
        }
    }
    for (int i = 0; i < n; i++)
        if (visited[i] == visited[n - i + n])
        {
            cout << "YES";
            return 0;
        }
    cout << "NO";
    return 0;
}

