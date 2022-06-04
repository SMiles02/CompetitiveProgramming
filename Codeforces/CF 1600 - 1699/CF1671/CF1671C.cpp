#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    int a[n];
    ll s = 0, ans = 0, d, c = -1, k = n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    sort(a, a + n);
    while (k > 0) {
        if (s > x) {
            --k;
            s -= a[k];
            continue;
        }
        d = (x - s) / k;
        ans += k * max(d - c, 0LL);
        c = max(c, d);
        --k;
        s -= a[k];
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