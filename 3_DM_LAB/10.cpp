#include <bits/stdc++.h>

using namespace std;
int coun = 0;

bool isPrime(vector<int> a)
{
    set<int> a;
    a.inser
}

void gen(vector<int> a, int n, int pos, int pred)
{
    if (n == 0 isPrime(a))
    {
        coun++;
        cout << a[0];
        for (int i = 1; i < pos; i++)
            cout << "+" << a[i];
        cout << endl;
        return;
    }
    for (int i = pred; i <= n; i++)
    {
        if (n - i == 0 || n - i >= i)
        {
            a[pos] = i;
            gen(a, n - i, pos + 1, i);
        }
    }
}

int main()
{
    //freopen ("partition.in","r",stdin);
    //freopen ("partition.out","w",stdout);
    int n;
    cin >> n;
    vector<int> pref(n);
    gen(pref, n, 0, 1);
    cout << coun;
    //fclose (stdout);
    //fclose (stdin);
}

