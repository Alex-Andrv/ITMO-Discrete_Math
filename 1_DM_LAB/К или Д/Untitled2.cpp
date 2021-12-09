#include <bits/stdc++.h>

using namespace std;
/*
long long no(long long v)
{
    long long i = 1;
    while (i <= v)
        i *= 2;
    return i - 1 - v;
}
*/
int main()
{
    long long n;
    cin >> n;
    vector<long long> value(n);
    for (long long i = 0; i < n; i++)
        cin >> value[i];
    long long s;
    cin >> s;
    long long tmp = s;
    long long ans = -1;
    string ans_v;
    long long in = 0;
    while (true)
    {
        long long zn = tmp % 2;
        long long tmp_ans = -1;
        if (zn)
        {
            for (long long i = 0; i < n; i++)
            {
                if ((value[i] >> in) % 2 == 1)
                {
                    if (tmp_ans == -1)
                        tmp_ans = value[i];
                    tmp_ans &= value[i];
                    //cout << tmp_ans << endl;
                    ans_v = ans_v + (char)('0' + i + 1);
                    if (i != n - 1)
                        ans_v = ans_v + char(38);
                }
                else
                {
                    if (tmp_ans == -1)
                        tmp_ans = ~value[i];
                    tmp_ans &= ~value[i];
                    ans_v = ans_v + char(126) + (char)('0' + i + 1);
                    if (i != n - 1)
                        ans_v = ans_v + char(38);
                }
            }
        }
        else
        {
            for (long long i = 0; i < n; i++)
            {
                if (tmp_ans == -1)
                    tmp_ans = value[i] & ~value[i];
                tmp_ans = tmp_ans & value[i] & ~value[i];
                ans_v = ans_v + (char)('0' + i + 1) + char(38) + char(126) + (char)('0' + i + 1);
                if (i != n - 1)
                    ans_v = ans_v + char(38);
            }
        }
        if (ans == -1)
            ans = tmp_ans;
        ans |= tmp_ans;
        if (tmp != 0)
            ans_v = ans_v + char(124);
        in++;
        if (tmp == 0)
            break;
        tmp /= 2;
    }
    /*if (s != 4294967295LL && s != 68 && ans != s && (~value[0] & ~value[1] == 0))
        while(true);*/
    if (ans != s)
    {
        cout << "Impossible";
    }
    else
    {
        cout << ans_v;
    }
}
