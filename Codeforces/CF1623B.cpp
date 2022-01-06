#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y, z;
    cin >> n;
    int b[n+1][2];
    array<int,4> a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1] >> a[i][2];
        a[i][0] = a[i][2] - a[i][1];
        b[i+1][0] = 1;
        b[i+1][1] = n;
    }
    sort(a, a + n, greater<array<int, 4>>());
    for (int i = 0; i < n; ++i) {
        if (a[i][1] == a[i][2])
            a[i][3] = a[i][1];
        if (i > 0) {
            x = b[a[i][1]][0];
            y = b[a[i][1]][1];
            if (a[i][1] == b[a[i][1]][0])
                z = a[i][2] + 1;
            else
                z = a[i][1] - 1;
            for (int j = 0; j < i; ++j)
                if (a[j][1] == x && a[j][2] == y)
                    a[j][3] = z;
            for (int j = 1; j <= n; ++j)
                if (b[j][0] == x && b[j][1] == y) {
                    if (j < z)
                        b[j][1] = z - 1;
                    else
                        b[j][0] = z + 1;
                }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < 4; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}