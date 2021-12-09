

#include <bits/stdc++.h>

using namespace std;

void gen(vector<int> a, int n, int pos, int k)
{
    if (pos == k)
    {
        for (int i = 0; i < k; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (((pos == 0 || a[pos - 1] < i + 1)) && (n - i - 1) >= k - (pos + 1))
        {
            a[pos] = i + 1;
            gen(a, n, pos + 1, k);
        }
    }
}

int main()
{
    freopen ("choose.in","r",stdin);
    freopen ("choose.out","w",stdout);
    int n, k;
    cin >> n >> k;
    vector<int> pref(k);
    gen(pref, n, 0, k);
    fclose (stdout);
    fclose (stdin);
}
