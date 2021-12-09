#include <bits/stdc++.h>

using namespace std;

map<char, set<string>> ass;

int main()
{
    std::freopen("epsilon.in", "r", stdin);
    std::freopen("epsilon.out", "w", stdout);
    int n;
    cin >> n;
    char start;
    cin >> start;
    set<char> se;
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
        if (w.empty())
            se.insert(t);
    }
    int old_size = 0;
    while (se.size() != old_size)
    {
        old_size = se.size();
        for (auto pa : ass)
        {
            for (auto el:pa.second)
            {
                bool zn = true;
                for (auto c: el)
                {
                    if (!(c >= 'A' && c <= 'Z' && se.count(c) != 0))
                    {
                        zn =false;
                        break;
                    }
                }
                if (zn)
                    se.insert(pa.first);
            }
        }
    }
    for (auto el: se)
        cout << el << endl;
}
