#include <bits/stdc++.h>

using namespace std;

const int sm = 1;
int c = 0;

void get_ans(vector<char> &ans, int pos, int bal, int n, long long k, stack<char> &last)
{
    //out << pos << " " << bal;
    if (pos == 2 * n && bal == 0)
    {
        cout << c << ": ";
        for (int i = 0; i < 2 * n; i++)
            cout << ans[i];
        cout << endl;
        c++;
        return;
    }
    if (bal < 0 || pos == 2 * n)
        return;
    if (bal <= n)
    {ans.push_back('(');
    last.push('(');
    get_ans(ans, pos + 1, bal + 1, n, k, last);
    last.pop();
    ans.pop_back();}
    if (!last.empty() && last.top() == '(')
    {
        ans.push_back(')');
        last.pop();
        get_ans(ans, pos + 1, bal - 1, n, k, last);
        last.push('(');
        ans.pop_back();

    }
    if (bal <= n)
    {ans.push_back('[');
    last.push('[');
    get_ans(ans, pos + 1, bal + 1, n, k, last);
    last.pop();
    ans.pop_back();}
    if (!last.empty() && last.top() == '[')
    {
        ans.push_back(']');
        last.pop();
        get_ans(ans, pos + 1, bal - 1, n, k, last);
        last.push('[');
        ans.pop_back();

    }
}

int main()
{
    //freopen ("num2brackets2.in","r",stdin);
    //freopen ("num2brackets2.out","w",stdout);
    int n;
    long long k;
    cin >> n >> k;
    vector<char> ans;
    stack<char> last;
    get_ans(ans, 0, 0, n, k, last);
    //fclose (stdout);
    //fclose (stdin);
}


