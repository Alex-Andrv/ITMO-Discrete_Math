#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ("mtf.in","r",stdin);
    freopen ("mtf.out","w",stdout);
    string st;
    cin >> st;
    string alf = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < st.size(); i++)
    {
        auto it = find(alf.begin(), alf.end(), st[i]);
        cout << it - alf.begin() + 1 << " ";
        alf.erase(it);
        alf = st[i] + alf;
    }
    fclose (stdout);
    fclose (stdin);
}



