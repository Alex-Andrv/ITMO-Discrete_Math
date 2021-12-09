#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen ("bwt.in","r",stdin);
    //freopen ("bwt.out","w",stdout);
    string st;
    cin >> st;
    int n = st.size();
    vector<string> arrSt;
    for (int i = 0; i < n; i++) {
        rotate(st.begin(), st.begin() + 1, st.end());
        arrSt.push_back(st);
    }
    sort(arrSt.begin(), arrSt.end());
    for (int i = 0; i < n; i++)
    {
        cout << arrSt[i][n - 1];
    }
    //fclose (stdout);
    //fclose (stdin);
}
