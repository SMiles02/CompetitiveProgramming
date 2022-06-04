#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n + 1), p(n + 1), cur(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        p[i] = p[i - 1] + v[i];
    }
    ll ans = p[n] * b;
    for (int i = 1; i <= n; ++i) {
        cur[i] = cur[i - 1] + (v[i] - v[i - 1]) * (a + b);
        ans = min(ans, cur[i] + (p[n] - p[i] - v[i] * (n - i)) * b);
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