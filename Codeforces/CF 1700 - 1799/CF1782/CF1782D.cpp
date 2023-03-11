#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool is_square(ll x) {
    ll s = sqrtl(x);
    return (s * s == x || (s - 1) * (s - 1) == x || (s + 1) * (s + 1) == x);
}

void solve() {
    int n;
    ll ans = 1, n1, n2;
    cin >> n;
    int a[n], y;
    set<ll> s;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int x = 1; x * x <= a[j] - a[i]; ++x)
                if ((a[j] - a[i]) % x == 0) {
                    y = (a[j] - a[i]) / x;
                    if ((y - x) & 1)
                        continue;
                    n2 = (x + y) / 2;
                    n1 = n2 - x;
                    n1 *= n1;
                    n2 *= n2;
                    if (a[i] <= n1 && n1 - a[i] == n2 - a[j])
                        s.insert(n1 - a[i]);
                }
    vector<array<ll, 2>> v;
    for (auto i : s)
        v.push_back({i, 0});
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < v.size(); ++j)
            if (is_square(v[j][0] + a[i]))
                ++v[j][1];
    for (int i = 0; i < v.size(); ++i)
        ans = max(ans, v[i][1]);
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}