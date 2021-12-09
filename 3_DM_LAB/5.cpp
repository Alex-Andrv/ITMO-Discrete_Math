#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen ("telemetry.in","r",stdin);
    freopen ("telemetry.out","w",stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < pow(k, n); i++) {
        for (int j = 0; j < n; j++) {
            int st = pow(k, j);
            if (((i / st) % (k * 2) == 0) || ((i / st) % (k * 2) == 5)) {
                cout << 0;
            } else if (((i / st) % (k * 2) == 1) || ((i / st) % (k * 2) == 4)) {
                cout << 1;
            } else {
                cout << 2;
            }
        }
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
