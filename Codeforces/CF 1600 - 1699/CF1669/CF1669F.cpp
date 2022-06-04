#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    int a[n], s = 0, c;
    map<int, int> pre;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    c = 0;
    for (int i = 0; i < n; ++i) {
        c += a[i];
        pre[c] = i + 1;
    }
    c = 0;
    for (int i = 1; i <= n; ++i) {
        c += a[n - i];
        if (c <= s / 2 && pre[c])
            ans = i + pre[c];
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