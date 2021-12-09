
#include <bits/stdc++.h>

using namespace std;

void gen(vector<int> a, int n, int pos)
{
    if (pos == n)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (find(a.begin(), a.begin() + pos, i + 1) == a.begin() + pos)
        {
            a[pos] = i + 1;
            gen(a, n, pos + 1);
        }
    }
}

int main()
{
    freopen ("permutations.in","r",stdin);
    freopen ("permutations.out","w",stdout);
    int n;
    cin >> n;
    vector<int> pref(n);
    gen(pref, n, 0);
    fclose (stdout);
    fclose (stdin);
}
