#include <bits/stdc++.h>

using namespace std;


bool nextbrackets(vector<int> &ans, int n)
{
    int i = n - 2;
    while (i >= 0 && ans[i] >= ans[i + 1])
        i--;
    if (i == -1)
        return false;
    int j;
    for (j = n - 1; j > 0; j--)
        if (ans[j] > ans[i])
            break;
    swap(ans[i], ans[j]);
    reverse(ans.begin() + i + 1, ans.end());
    return true;
}

int main()
{
    freopen ("nextmultiperm.in","r",stdin);
    freopen ("nextmultiperm.out","w",stdout);
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        cin >> ans[i];
    /*while (nextbrackets(ans, n))
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }*/
    if (!nextbrackets(ans, n))
        for (int i = 0; i < n; i++)
            cout << '0' << " ";
    else
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
    fclose (stdout);
    fclose (stdin);
}






