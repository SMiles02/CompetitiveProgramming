#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x = 0, k;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    while (m--) {
        cin >> k;
        x = (x + k) % n;
    }
    cout << a[x] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}