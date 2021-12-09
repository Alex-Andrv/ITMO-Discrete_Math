#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ("allvectors.in","r",stdin);
    freopen ("allvectors.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = n - 1; j >= 0; j--)
            cout << ((i >> j) & 1);
        cout << endl;
    }
    fclose (stdout);
    fclose (stdin);
}
