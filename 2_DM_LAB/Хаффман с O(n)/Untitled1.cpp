#include <bits/stdc++.h>

using namespace std;

int  main()
{
    ifstream fin("huffman.in");
    ofstream fout("huffman.out");
    int  n;
    fin >> n;
    vector<long long> arr(n + 2, (long long) 1e16);
    for (long long  i = 0; i < n; i++)
        fin >> arr[i];
    vector<long long> a(n + 2, (long long) 1e16);
    sort(arr.begin(), arr.end());
    long long  sum = 0;
    int i = 0, j = 0;
    for (int  k = 0; k < (n - 1); k++)
    {
        long long  sum1 = arr[i] + arr[i + 1];
        long long  sum2 = arr[i] + a[j];
        long long  sum3 = a[j] + a[j + 1];
        if (sum1 <= sum2 && sum1 <= sum3)
        {
            sum += sum1;
            i += 2;
            a[k] = sum1;
        }
        else
        {
            if (sum2 <= sum3 && sum2 <= sum1)
            {
                sum += sum2;
                i++;
                j++;
                a[k] = sum2;
            }
            else
            {
                sum += sum3;
                j += 2;
                a[k] = sum3;
            }
        }
    }
    fout << sum;
    fin.close();
    fout.close();
}
