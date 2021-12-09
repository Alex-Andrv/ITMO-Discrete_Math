#include <bits/stdc++.h>

using namespace std;


void gen(vector<int> a, int n, int pos, int pred)
{

    for (int i = 0; i < pos; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = pred + 1; i <= n; i++)
    {
        a[pos] = i;
        gen(a, n, pos + 1, i);
    }
}

int main()
{
    freopen ("subsets.in","r",stdin);
    freopen ("subsets.out","w",stdout);
    int n;
    cin >> n;
    vector<int> pref(n + 1);
    gen(pref, n, 0, 0);
    fclose (stdout);
    fclose (stdin);
}

