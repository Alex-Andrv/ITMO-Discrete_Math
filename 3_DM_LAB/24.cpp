#include <bits/stdc++.h>

using namespace std;


void next(vector<int> ans, int n)
{
    set<int> visi;
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        visi.insert(ans[i]);
        auto it = visi.upper_bound(ans[i]);
        if (it != visi.end())
        {
            ans[i] = *it;
            visi.erase(it);
            break;
        }
    }
    if (i < 0)
    {
        for (int j = 0; j < n; j++)
            cout << '0' << " ";
        cout << endl;
        return;
    }
    i++;
    int k = 1;
    auto it = visi.begin();
    for (int j = i; j < n; j++)
    {
        ans[j] = *it;
        it++;
    }
    for (int j = 0; j < n; j++)
        cout << ans[j] << " ";
    cout << endl;
    return;
}

void prev(vector<int> ans, int n)
{
    set<int> visi;
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        visi.insert(ans[i]);
        auto it = visi.lower_bound(ans[i]);
        if (it != visi.begin())
        {
            it--;
            ans[i] = *it;
            visi.erase(it);
            break;
        }
    }
    if (i < 0)
    {
        for (int j = 0; j < n; j++)
            cout << '0' << " ";
        cout << endl;
        return;
    }
    i++;
    int k = 1;
    auto it = visi.end();
    for (int j = i; j < n; j++)
    {
        it--;
        ans[j] = *it;
    }
    for (int j = 0; j < n; j++)
        cout << ans[j] << " ";
    cout << endl;
    return;
}

int main()
{
    freopen ("nextperm.in","r",stdin);
    freopen ("nextperm.out","w",stdout);
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++)
        cin >> ans[i];
    prev(ans, n);
    next(ans, n);
    fclose (stdout);
    fclose (stdin);
}




