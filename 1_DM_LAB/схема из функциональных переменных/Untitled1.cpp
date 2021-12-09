#include <bits/stdc++.h>

using namespace std;

struct node
{
    vector<int> child;
    vector<int> answer;
    int m;
    int depth;
    node(int m1 = 0, int d = 0)
    {
        m = m1;
        depth = d;
        answer.resize(1 << m);
        child.resize(m);
    }
};

int ans(int in, vector<node> &arr, vector<int> &value)
{
    /*for (int i = 0; i < value.size(); i++)
            cout << value[i] << " ";
        cout << endl;*/
    if (value[in] != -1)
        return value[in];
    int ind = 0;
    for (int i = 0; i < arr[in].m; i++)
    {
        ind = ind * 2 + ans(arr[in].child[i], arr, value);
    }
    return value[in] = arr[in].answer[ind];
}

int main()
{
    int n;
    cin >> n;
    vector<node> arr;
    vector<int> value(n, -1);
    vector<int> sheet;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (m == 0)
        {
            arr.push_back(node(m, 0));
            sheet.push_back(i);
        }
        else
        {
            arr.push_back(node(m, 0));
            for (int j = 0; j < m; j++)
            {
                int tmp;
                cin >> tmp;
                tmp--;
                arr[i].child[j] = tmp;
                arr[i].depth = max(arr[i].depth, arr[tmp].depth + 1);
            }
            for (int j = 0; j < 1 << m; j++)
            {
                int tmp;
                cin >> tmp;
                arr[i].answer[j] = tmp;
            }
        }
    }
    cout << arr[n - 1].depth << endl;
    for (int i = 0; i < 1 << sheet.size(); i++)
    {
        int tmp = i;
        for (int j = sheet.size() - 1; j >= 0; j--)
        {
            int in = sheet[j];
            value[in] = tmp % 2;
            tmp /= 2;
        }
        cout << ans(n - 1, arr, value);
        value = vector<int> (n, -1);
      //  cout << "!!!! " << endl;
    }
}
