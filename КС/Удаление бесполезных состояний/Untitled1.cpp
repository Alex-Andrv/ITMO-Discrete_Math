#include <bits/stdc++.h>

using namespace std;

map<char, set<string>> ass;

void dfs(char start, vector<bool> &used)
{
    used[start - 'A'] = true;
    if (ass.count(start) == 0)
    return;
    for (auto w: ass[start])
    {
        for (auto c: w)
        {
            if (c >= 'A' && c <= 'Z' && !used[c - 'A'])
            {
                dfs(c, used);
            }
        }
    }
}

int main()
{
    std::freopen("useless.in", "r", stdin);
    std::freopen("useless.out", "w", stdout);
    vector<bool> used(26, true);
    int n;
    cin >> n;
    char start;
    cin >> start;
    used[start - 'A'] = false;
    vector<bool> s(26, false);
    string line;
    int co = 0;
    getline(cin, line);
    cout << line;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        istringstream ss(line);
        char t;
        ss >> t;
        used[t - 'A'] = false;
        char c;
        ss >> c >> c;
        string w;
        ss >> w;
        for (auto el: w)
            if (el >= 'A' && el <= 'Z')
                used[el - 'A'] = false;
        ass[t].insert(w);
        //if (w.size() > 0 && w[0] == ' ')
        //while (true);
        bool zn = true;
        for (auto el: w)
            if (el >= 'A' && el <= 'Z')
            {
                zn = false;
                break;
            }
        if (!s[t - 'A'] && zn)
        {
            s[t - 'A'] = true;
            co++;
        }
    }
    int old_size = 0;
    while (co != old_size)
    {
        old_size = co;
        for (auto pa : ass)
        {
            for (auto el:pa.second)
            {
                bool zn = true;
                for (auto c: el)
                {
                    if (!((c >= 'A' && c <= 'Z' && s[c - 'A']) || (c >= 'a' && c <= 'z')))
                    {
                        zn = false;
                        break;
                    }
                }
                if (!s[pa.first - 'A'] && zn)
                {
                    s[pa.first - 'A'] = true;
                    co++;
                }
            }
        }
    }
    set<char> ans;
    set<pair<char, string>> dead;
    for (int i = 0; i < 26; i++)
    {
        if (!s[i] && !used[i])
        {
            ans.insert(i + 'A');
            ass.erase(i + 'A');
            for (auto el: ass)
                for (auto w : el.second)
                    for (auto c : w)
                        if (c == i + 'A')
                        {
                            dead.insert({el.first, w});
                            break;
                        }
        }
    }
    for (auto kill: dead) {
        if (ass.count(kill.first) != 0)
        ass[kill.first].erase(kill.second);
    }
    dfs(start, used);
    for (int i = 0; i < 26; i++)
    {
        if (!used[i])
        {
            ans.insert(i + 'A');
            ass.erase(i + 'A');
        }
    }
    for (auto el: ans)
        cout << el << " ";
    //cout << endl;
    /*for (auto el: ass)
    {
        cout << el.first << "->";
        for (auto w : el.second)
            cout << w << " ";
        cout << endl;
    }*/
}
