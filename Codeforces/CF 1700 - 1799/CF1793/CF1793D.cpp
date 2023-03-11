#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll x) {
    return (x * (x + 1)) / 2;
}

bool in_range(int l, int r, int x) {
    return (l <= x && x <= r);
}

void solve() {
    int n, k, a, b, x, y;
    ll ans = 0, cur;
    cin >> n;
    int p[n + 1], q[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        p[k] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        q[k] = i;
    }
    a = p[1];
    b = q[1];
    ans += f(min(p[1], q[1]) - 1) + f(n - max(p[1], q[1])) + f(max(p[1], q[1]) - min(p[1], q[1]) - 1);
    for (int i = 1; i < n; ++i) {
        a = min({a, p[i], q[i]});
        b = max({b, p[i], q[i]});
        x = p[i + 1];
        y = q[i + 1];
        if (in_range(a, b, x) || in_range(a, b, y))
            continue;
        if (max(x, y) < a)
            cur = 1LL * (a - max(x, y)) * (n - b + 1);
        else if (b < min(x, y))
            cur = 1LL * (min(x, y) - b) * a;
        else if (x < a)
            cur = 1LL * (a - x) * (y - b);
        else
            cur = 1LL * (a - y) * (x - b);
        ans += cur;
    }
    ++ans;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}