#include <bits/stdc++.h>

using namespace std;

bool accept(vector<bool> &T, vector<vector<vector<int>>> &d, string &word)
{
    vector<vector<bool>>  can(word.size() + 2, vector<bool>(d.size()));
    can[0][0] = true;
    for (int i = 0; i < word.size(); i++)
    {
        int c = word[i] - 'a';
        for (int j = 0; j < d.size(); j++)
        {
            if (can[i][j])
            {
                for (auto el : d[j][c])
                {
                    can[i + 1][el] = true;
                }
            }
        }
    }
    for (int i = 0; i < d.size(); i++)
        if (can[word.size()][i] && T[i])
            return true;
    return false;
}

int main()
{
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
    string st;
    cin >> st;
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> T(n);
    for (int i = 0; i < k; i++)
    {
        int buf;
        cin >> buf;
        T[buf - 1] = true;
    }
    vector<vector<vector<int>>> d(n, vector<vector<int>> (33));
    for (int ind = 0; ind < m; ind++)
    {
        int i, j;
        char c;
        cin >> i >> j >> c;
        d[i - 1][c - 'a'].push_back(j - 1);
    }
    cout << (accept(T, d, st) ? "Accepts" : "Rejects");
}
