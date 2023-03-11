#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, cnt = 0, mx = -1e9;
    ll ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= 0) {
            ++cnt;
            mx = max(mx, a[i]);
        }
        ans += abs(a[i]);
    }
    if (cnt & 1)
        ans += mx * 2;
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