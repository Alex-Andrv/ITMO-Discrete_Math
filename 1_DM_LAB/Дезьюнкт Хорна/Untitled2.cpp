#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(k);
    vector<int> alive(k);
    vector<bool> value(k, false);
    vector<int> ans(n, -1);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp != -1)
                alive[i]++;
            arr[i].push_back(tmp);
        }
        if (alive[i] == 0)
            value[i] = true;
    }
    while (true)
    {
        bool zn = true;
        for (int i = 0; i < k; i++)
        {
            if (alive[i] == 1)
            {
                zn = false;
                for (int j = 0; j < n; j++)
                {
                    if (arr[i][j] != -1)
                    {
                        if (ans[j] == -1)
                        {
                            ans[j] = arr[i][j];
                            alive[i] = -1;
                        }
                        else
                        {
                            if (ans[j] == arr[i][j])
                            {
                                alive[i] = -1;
                            }
                            else
                            {
                                cout << "YES";
                                return 0;
                            }
                        }
                    }
                }
                alive[i] = -1;
            }
        }
        if (zn)
        {
            cout << "NO";
            return 0;
        }
        for (int i = 0; i < k; i++)
        {
            if (alive[i] > 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr[i][j] != -1 && ans[j] != -1)
                    {
                        value[i] = value[i] || ((arr[i][j] + ans[j] + 1) % 2);
                        arr[i][j] = -1;
                        alive[i]--;
                    }
                }
                if (!value[i] && alive[i] == 0)
                {
                    cout << "YES";
                    return 0;
                }
                if (value[i])
                    alive[i] = -1;
            }
        }
    }
}
