#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, ans = 0;
    cin >> m;
    int a[m];
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    for (int i = 1; i < m; i *= 2)
        for (int j = 0; j < m; j += i * 2) {
            if (a[j] > a[j + i]) {
                swap(a[j], a[j + i]);
                ++ans;
            }
            if (a[j + i] - a[j] != i) {
                cout << "-1\n";
                return;
            }
        }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}