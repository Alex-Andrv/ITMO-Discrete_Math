#include <bits/stdc++.h>

using namespace std;

bool check(string &f, string &s, int n)
{
    for (int i = 0; i < n; i++)
        if (f[i] < s[i])
        {
            return false;
        }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(1 << n);
    vector<int> f(1 << n);
    for (int i = 0; i < 1 << n; i++)
    {
        string b;
        cin >> b;
        arr[i] = b;
        int buf;
        cin >> buf;
        f[i] = buf;
    }
    for (int i = 0; i < 1 << n; i++)
    {
        cout << arr[i] << " ";
        int ax = 0;
        for (int j = i; j >= 0; j--)
        {
            if (check(arr[i], arr[j], n))
            {
                ax = ax ^ f[j];
            }
        }
        cout << ax << endl;
    }
}
