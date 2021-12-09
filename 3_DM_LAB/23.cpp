#include <bits/stdc++.h>

using namespace std;


void next(vector<int> ans)
{
    int i = 0;
    while (i < ans.size() && ans[i] == 1)
    {
        i++;
    }
    if (ans.size() == i)
    {
        cout << '-' << endl;
        return;
    }
    else
        ans[i] = 1;
    i--;
    while (i >= 0)
    {
        ans[i] = 0;
        i--;
    }
    i = ans.size() - 1;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
}

void prev(vector<int> ans)
{
    int i = 0;
    while (i < ans.size() && ans[i] == 0)
    {
        i++;
    }
    if (ans.size() == i)
    {
        cout << '-' << endl;
        return;
    }
    ans[i] = 0;
    i--;
    while (i >= 0)
    {
        ans[i] = 1;
        i--;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
}

int main()
{
    freopen ("nextvector.in","r",stdin);
    freopen ("nextvector.out","w",stdout);
    vector<int> ans;
    char b;
    while (cin >> b)
    {
        ans.push_back(b - '0');
    }
    reverse(ans.begin(), ans.end());
    prev(ans);
    next(ans);
    fclose (stdout);
    fclose (stdin);
}



