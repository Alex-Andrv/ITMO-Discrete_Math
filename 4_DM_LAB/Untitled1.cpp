#include <bits/stdc++.h>

using namespace std;

bool accept(vector<bool> &T, map<pair<int, char>, int> &d, string &word)
{
    int start = 1;
    for (auto b : word)
    {
        if (d.find({start, b}) != d.end())
        {
            start = d.find({start, b}) -> second;
        } else
            return false;
    }
    return T[start];
}

int main()
{
    freopen("problem1.in", "r", stdin);
    freopen("problem1.out", "w", stdout);
    string st;
    cin >> st;
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> T(n + 1);
    for (int i = 0; i < k; i++)
    {
        int buf;
        cin >> buf;
        T[buf] = true;
    }
    map<pair<int, char>, int> d;
    for (int ind = 0; ind < m; ind++)
    {
        int i, j;
        char c;
        cin >> i >> j >> c;
        d[ {i, c}] = j;
    }
    cout << (accept(T, d, st) ? "Accepts" : "Rejects");
}
