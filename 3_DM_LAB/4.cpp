#include <bits/stdc++.h>

using namespace std;

void coutf(int zn, int n)
{
    if (n == 1)
    {
        cout << zn % 2;
        return;
    }
    coutf(zn / 2, n - 1);
    cout << zn % 2;
    return;
}


int main()
{
    freopen ("chaincode.in","r",stdin);
    freopen ("chaincode.out","w",stdout);
    int n;
    cin >> n;
    int a[1 << n];
    for (int i = 0; i < (1 << n); i++)
        a[i] = 0;
    int zn = 0;
    do
    {
        a[zn] = 1;
        coutf(zn, n);
        cout << endl;
        if (a[(zn * 2) % (1 << n) + 1] == 0)
            zn = (zn * 2) % (1 << n) + 1;
        else
            zn = (zn * 2) % (1 << n);
    }
    while (zn != 0);
    fclose (stdout);
    fclose (stdin);
}
