#include <bits/stdc++.h>

using namespace std;


bool nextpartition(vector<int> &ans, int n)
{
    if (ans.size() == 1)
        return false;
    ans[ans.size() - 1]--;
    ans[ans.size() - 2]++;
    if (ans[ans.size() - 1] < ans[ans.size() - 2])
    {
        ans[ans.size() - 2] += ans[ans.size() - 1];
        ans.pop_back();
    }
    else
    {
        while (ans[ans.size() - 1] >= ans[ans.size() - 2] * 2)
        {
            ans.push_back(ans[ans.size() - 1] - ans[ans.size() - 2]);
            ans[ans.size() - 2] = ans[ans.size() - 3];
        }
    }
    return true;
}

int main()
{
    //freopen ("nextpartition.in","r",stdin);
    //freopen ("nextpartition.out","w",stdout);
    int n;
    cin >> n;
    vector<int> ans;
    char c;
    while (cin >> c)
    {
        int b;
        cin >> b;
        ans.push_back(b);
    }
    if (!nextpartition(ans, n))
        cout << "No solution";
    else
    {
        cout << n << '=' << ans[0];
        for (int i = 1; i < ans.size() ; i++)
        {
            cout << "+" << ans[i];
        }
    }
    //fclose (stdout);
    //fclose (stdin);
}
