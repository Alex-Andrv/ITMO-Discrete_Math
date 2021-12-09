#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ("antigray.in","r",stdin);
    freopen ("antigray.out","w",stdout);
    int n;
    cin >> n;
    int m = pow(3, n - 1);
    for (int i = 0; i < m; i++)
    {
        for (int h = 0; h < 3; h++)
        {
            int b = i;
            string st;
            for (int j = n - 1; j >= 0; j--)
            {
                st.insert(0, 1, ('0' + ((b % 3 + h) % 3)));
                b /= 3;
            }
            cout << st <<  endl;
        }
    }
    fclose (stdout);
    fclose (stdin);
}
