#include <bits/stdc++.h>

using namespace std;

map<char, multiset<string>> ass;

long long M = 1e9 + 7;

void CYK(char S, string &w)
{
    vector<vector<vector<long long>>> dp(26, vector<vector<long long>> (w.size(), vector<long long> (w.size(), 0)));
    for (int i = 0; i < w.size(); i++)
        for (int A = 0; A < 26; A++)
        {
            dp[A][i][i] = ass[A + 'A'].count(string(1, w[i]));
        }
    for (int l = 1; l < w.size(); l++)
        for (int i = 0; i + l < w.size(); i++)
            for (int A = 0; A < 26; A++)
            {
                for (auto el : ass[A + 'A']) {
                    if (el.size() != 2)
                        continue;
                    for (int k = i; k < i + l; k++)
                    {
                        dp[A][i][i + l] = (dp[A][i][i + l] + (dp[el[0] - 'A'][i][k] * dp[el[1] - 'A'][k + 1][i + l]) % M) % M;
                    }
                }
            }
    cout << dp[S - 'A'][0][w.size() - 1];
}

void get(int n)
{
    string line;
    getline(cin, line);
    cout << line;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        istringstream ss(line);
        char t;
        ss >> t;
        char c;
        ss >> c >> c;
        string w;
        ss >> w;
        ass[t].insert(w);
    }
}

int main()
{
    std::freopen("nfc.in", "r", stdin);
    std::freopen("nfc.out", "w", stdout);
    int n;
    cin >> n;
    char start;
    cin >> start;
    get(n);
    string w;
    cin >> w;
    CYK(start, w);
}
