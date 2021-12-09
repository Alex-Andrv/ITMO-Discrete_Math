#include <bits/stdc++.h>

using namespace std;

map<char, set<string>> ass;
map<pair<char, string>, int> bj;


void CYK(char S, string &w, int co) {
    vector<vector<vector<bool>>> dp(26, vector<vector<bool>>(w.size() + 1, vector<bool>(w.size() + 1, false)));
    vector<vector<vector<vector<bool>>>> h(co, vector<vector<vector<bool>>>());
    for (int i = 0; i <= w.size(); i++)
        for (int A = 0; A < 26; A++) {
            if (i != w.size())
                dp[A][i][i + 1] = ass[A + 'A'].count(string(1, w[i]));
            dp[A][i][i] = ass[A + 'A'].count("");
            if (i == 0)
                for (auto el : ass[A + 'A']) {
                    h[bj[{A + 'A', el}]].resize(el.size() + 1,
                                               vector<vector<bool>>(w.size() + 1, vector<bool>(w.size() + 1, false)));
                }
            for (auto el : ass[A + 'A']) {
                h[bj[{A + 'A', el}]][0][i][i] = true;
            }
        }
    for (int cnt = 0; cnt < 25; cnt++) {
        for (int l = 1; l <= w.size(); l++)
            for (int i = 0; i + l <= w.size(); i++) {
                int j = i + l;
                for (auto el : bj) {
                    int max_k = h[el.second].size();
                    for (int k = 1; k < max_k; k++) {
                        if (el.first.second[k - 1] >= 'A' && el.first.second[k - 1] <= 'Z')
                            for (int r = i; r <= j; r++) {
                                h[el.second][k][i][j] = h[el.second][k][i][j] |
                                                        (h[el.second][k - 1][i][r] &
                                                         dp[el.first.second[k - 1] - 'A'][r][j]);
                            }
                        else
                            h[el.second][k][i][j] = (h[el.second][k - 1][i][j - 1] &&
                                                     el.first.second[k - 1] == w[j - 1]);
                    }
                }
                for (int A = 0; A < 26; A++) {
                    for (auto el : ass[A + 'A']) {
                        dp[A][i][j] = dp[A][i][j] | h[bj[{A + 'A', el}]][el.size()][i][j];
                    }
                }
            }
    }
    cout << (dp[S - 'A'][0][w.size()] ? "yes" : "no");
}

void get(int n, int &co) {
    string line;
    getline(cin, line);
    cout << line;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        istringstream ss(line);
        char t;
        ss >> t;
        char c;
        ss >> c >> c;
        string w;
        ss >> w;
        ass[t].insert(w);
        if (bj.count({t, w}) == 0)
            bj[{t, w}] = co++;
    }
}

int main() {
    std::freopen("cf.in", "r", stdin);
    std::freopen("cf.out", "w", stdout);
    int n;
    cin >> n;
    char start;
    cin >> start;
    int co = 0;
    get(n, co);
    string w;
    cin >> w;
    CYK(start, w, co);
}
