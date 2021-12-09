#include <bits/stdc++.h>

using namespace std;

void gen(vector<vector<int>> &a, int n, int k)
{
   // cout << n << " " << k << endl;
    if (n == 0 && k == 0)
    {
        for (int i = 1; i < a.size(); i++)
        {
            for (int j = int(a[i].size()) - 1; j > -1; j--)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }
    if (n == 0 || k == 0 || n < k)
        return;
    a[k].push_back(n);
    gen(a, n - 1, k - 1);
    a[k].pop_back();
    for (int i = 1; i <= k; i++)
    {
        a[i].push_back(n);
        gen(a, n - 1, k);
        a[i].pop_back();
    }
}

int main()
{
    freopen ("part2sets.in","r",stdin);
    freopen ("part2sets.out","w",stdout);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> pref(k + 1);
    gen(pref, n, k);
    fclose (stdout);
    fclose (stdin);
}


