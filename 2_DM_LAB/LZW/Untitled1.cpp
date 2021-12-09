#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ("lzw.in","r",stdin);
    freopen ("lzw.out","w",stdout);
    string st;
    cin >> st;
    string alf = "abcdefghijklmnopqrstuvwxyz";
    vector<string> slov;
    for (int i = 0; i < alf.size(); i++)
    {
        string buf_st;
        buf_st = alf[i];
        slov.push_back(buf_st);
    }
    string buf;
    buf = st[0];
    auto mit = find(slov.begin(), slov.end(), buf);
    for (int i = 1; i < st.size(); i++)
    {
        //cout << buf << endl;
        auto it = find(slov.begin(), slov.end(), buf + st[i]);
        if (it != slov.end())
        {
            mit = it;
            buf += st[i];
            mit = it;
        }
        else
        {
            cout << mit - slov.begin() << " ";
            slov.push_back(buf + st[i]);
            buf = st[i];
            mit = find(slov.begin(), slov.end(), buf);
        }
    }
    cout << mit - slov.begin();
    fclose (stdout);
    fclose (stdin);
}
