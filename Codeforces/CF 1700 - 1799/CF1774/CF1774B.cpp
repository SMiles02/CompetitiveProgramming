#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[m];
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    if (m < k) {
        cout << "NO\n";
        return;
    }
    sort(a, a + m, greater<int>());
    for (int i = 0; i < k; ++i)
        if (a[i] > (n - i + k - 1) / k) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}