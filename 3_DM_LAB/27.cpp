#include <bits/stdc++.h>

using namespace std;


bool nextbrackets(vector<char> &ans)
{
    int open = 0, close = 0;
    int i;
    for (i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] == '(')
        {
            open++;
            if (close - open > 0)
            {
                ans[i] = ')';
                close--;
                break;
            }

        }
        else
            close++;
    }
    if (i == -1)
        return false;
    i++;
    for (int j = 0; j < open; j++)
        ans[i + j] = '(';
    for (int j = 0; j < close; j++)
        ans[i + j + open] = ')';
    return true;
}

int main()
{
    freopen ("nextbrackets.in","r",stdin);
    freopen ("nextbrackets.out","w",stdout);
    vector<char> ans;
    char c;
    while (cin >> c)
    {
        ans.push_back(c);
    }
    if (!nextbrackets(ans))
        cout << '-';
    else
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
    fclose (stdout);
    fclose (stdin);
}






