
#include <bits/stdc++.h>

using namespace std;

int mod = (int)(1e9 + 7);

int get_count(vector<vector<int>> &in, vector<int> &T, int l)
{
    int n = in.size();
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
    for (auto node : T) {
        ans = (ans + count_w[l][node]) % mod;
    }
    return ans;
}

void get_DFA(vector<vector<vector<int>>> &out, bitset<101> &T, vector<vector<int>> &in_dfa, vector<int> &T_dfa)
{
    queue<int> q;
    unordered_map<bitset<101>, int> get_num;
    unordered_map<int, bitset<101>> get_bit;
    bitset<101> test;
    test[0] = true;
    get_num[test] = 0;
    get_bit[0] = test;
    q.push(0);
    in_dfa.push_back(vector<int>());
    int next_num = 1;
    while (!q.empty())
    {
        int num = q.front();
        bitset<101> du = get_bit[num];
        q.pop();
        for (int c = 'a'; c <= 'z'; c++)
        {
            bitset<101> dv;
            for (int bit = 0; bit < 101; bit++)
            {
                if (du[bit])
                {
                    for (auto el : out[bit][c - 'a'])
                    {
                        dv[el] = true;
                    }
                }
            }
            if (get_num.count(dv) == 0)
            {
                get_num[dv] = next_num;
                get_bit[next_num] = dv;
                q.push(next_num);
                next_num++;
                in_dfa.push_back(vector<int>());
            }
            in_dfa[get_num[dv]].push_back(num);
        }
        if ((du & T).any())
        {
            T_dfa.push_back(num);
        }
    }
}

int main() {
    freopen("problem5.in", "r", stdin);
    freopen("problem5.out", "w", stdout);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    bitset<101> T;
    for (int i = 0; i < k; i++)
    {
        int ind;
        cin >> ind;
        T[--ind] = true;
    }
    vector<vector<vector<int>>> out(n, vector<vector<int>> (33));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        out[--a][c - 'a'].push_back(--b);
    }
    vector<vector<int>> in_DFA;
    vector<int> T_DFA;
    get_DFA(out, T, in_DFA, T_DFA);
    cout << get_count(in_DFA, T_DFA, l);
}
