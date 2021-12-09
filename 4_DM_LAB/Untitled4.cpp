
#include <bits/stdc++.h>

using namespace std;

int mod = (int)(1e9 + 7);


int main() {
    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    bitset<101> T;
    for (int i = 0; i < k; i++)
    {
        int ind;
        cin >> ind;
        T[--ind] = true;
    }
    vector<vector<int>> in(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        in[--b].push_back(--a);
    }
    vector<vector<int>> count_w(l + 1, vector<int> (n));
    count_w[0][0] = 1;
    for (int i = 1; i <= l; i++)
        for (int j = 0; j < n; j++)
    {
        for (auto node : in[j]) {
            count_w[i][j] = (count_w[i][j] + count_w[i - 1][node]) % mod;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
            if (T[i])
        ans = (ans + count_w[l][i]) % mod;
    }
    cout << ans;
}
