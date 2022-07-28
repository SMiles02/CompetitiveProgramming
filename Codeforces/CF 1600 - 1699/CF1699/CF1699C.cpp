#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int mul(int a, int b) { return (1LL * a * b) % MOD; }

void solve() {
    int n, l, r, ans = 1;
    cin >> n;
    int a[n], p[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    l = r = p[0];
    for (int i = 1; i < n; ++i) {
        l = min(l, p[i]);
        r = max(r, p[i]);
        if (p[i] != l && p[i] != r)
            ans = mul(ans, r - l - i + 1);
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