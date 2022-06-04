#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool ok(ll days, ll trgt, vector<int>& v) {
    ll ones = (days + 1) / 2, twos = days / 2, sm = 0;
    for (int i : v) {
        if ((trgt - i) & 1)
            --ones;
        sm += trgt - i - ((trgt - i) & 1);
    }
    return !(ones < 0 || ones + twos * 2 < sm);
}

void solve() {
    int n, mx = 0;
    ll ans = 1e18, l, r, m;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    l = 0; r = 1e15;
    while (l < r) {
        m = l + (r - l) / 2;
        if (ok(m, mx, v))
            r = m;
        else
            l = m + 1;
    }
    ans = min(ans, l);
    l = 0; r = 1e15;
    while (l < r) {
        m = l + (r - l) / 2;
        if (ok(m, mx + 1, v))
            r = m;
        else
            l = m + 1;
    }
    ans = min(ans, l);
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