#include <bits/stdc++.h>

using namespace std;


map<char, set<string>> ass;

bool check (char start, int pos, string w)
{
    if (pos + 1 == w.size())
    {
        for (auto el: ass[start])
        {
            if (el.size() == 1 && el[0] == w[pos])
                return true;
        }
        return false;
    }
    for (auto el: ass[start]) {
        if (el.size() == 1)
            continue;
        if (el[0] == w[pos])
            if (check(el[1], pos + 1, w))
            return true;
    }
    return false;
}

int main()
{
    std::freopen("automaton.in", "r", stdin);
    std::freopen("automaton.out", "w", stdout);
    int n;
    cin >> n;
    char start;
    cin >> start;
    for (int  i = 0; i < n; i++)
    {
        char t;
        cin >> t;
        char c;
        cin >> c >> c;
        string a;
        cin >> a;
        //cout << t << "->" << a << endl;
        ass[t].insert(a);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string w;
        cin >> w;
        cout << (check(start, 0, w) ? "yes" : "no") << endl;
    }
}
