
#include <bits/stdc++.h>

using namespace std;

bool isomorphism(int n1, int m1, int k1, vector<bool> &T1, vector<vector<int>> &out1,
                 int n2, int m2, int k2, vector<bool> &T2, vector<vector<int>> &out2)
{
    vector<bool> visi1(n1);
    vector<bool> visi2(n2);
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        pair<int, int> n = q.front();
        int f = n.first;
        int s = n.second;
        visi1[f] = visi2[s] = true;
        q.pop();
        if (T1[f] != T2[s])
                return false;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (out1[f][c - 'a'] != -1 && out2[s][c - 'a'] != -1)
            {
                if (visi1[out1[f][c - 'a']] != visi2[out2[s][c - 'a']])
                    return false;
                if (visi1[out1[f][c - 'a']] == -1)
                    q.push({out1[f][c - 'a'], out2[s][c - 'a']});
            } else
            {
                if ((out1[f][c - 'a'] != -1) != (out2[s][c - 'a'] != -1))
                    return false;
            }
        }
    }
    return true;
}


int main()
{
    freopen("isomorphism.in", "r", stdin);
    freopen("isomorphism.out", "w", stdout);
    int n1, m1, k1;
    cin >> n1 >> m1 >> k1;
    vector<bool> T1(n1);
    for (int i = 0; i < k1; i++)
    {
        int ind;
        cin >> ind;
        T1[--ind] = true;
    }
    vector<vector<int>> out1(n1, vector<int> (33, -1));
    for (int i = 0; i < m1; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        out1[--a][c - 'a'] = --b;
    }
    int n2, m2, k2;
    cin >> n2 >> m2 >> k2;
    vector<bool> T2(n2);
    for (int i = 0; i < k2; i++)
    {
        int ind;
        cin >> ind;
        T2[--ind] = true;
    }
    vector<vector<int>> out2(n2, vector<int> (33, -1));
    for (int i = 0; i < m2; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        out2[--a][c - 'a'] = --b;
    }
    cout << (isomorphism(n1, m1, k1, T1, out1, n2, m2, k2, T2, out2) ? "YES" : "NO");
}
