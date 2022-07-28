#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    ll p[n + 1], cur;
    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    ll ans = p[n] - 1LL * n * k;
    for (int i = n; i > 0; --i) {
        cur = 0;
        for (int j = i, cd = 1; j <= n && cd < 30; ++j, ++cd)
            cur += a[j] / (1 << cd);
        ans = max(ans, p[i - 1] + cur - 1LL * (i - 1) * k);
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