#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ("gray.in","r",stdin);
    freopen ("gray.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        int buf = i ^ (i / 2);
        for (int j = n - 1; j >= 0; j--)
            cout << ((buf >> j) & 1);
        cout << endl;
    }
    fclose (stdout);
    fclose (stdin);
}
