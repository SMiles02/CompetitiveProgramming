#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

struct BIT {
    int n;
    ll rtn; // rtn might need to be LLed
    vector<ll> bit;
    BIT(int n) : n(n), bit(n + 1,0) {}
    void update(int x, ll d) { for (int i = x; i <= n; i += i & -i) bit[i] += d; }
    ll query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit[i];
        return rtn;
    }
    ll query(int x, int y) { return query(y) - query(x - 1); }
};

void solve() {
    int n, c, t, cur;
    ll sm, ans = 0;
    cin >> n >> c;
    int a[n + 1], p[n + 1];
    array<int, 2> b[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = {a[i] + min(i, n - i + 1), i};
    }
    sort(b + 1, b + n + 1);
    BIT bit1(n), bit2(n);
    for (int i = 1; i <= n; ++i) {
        bit1.update(i, 1);
        bit2.update(i, b[i][0]);
        p[b[i][1]] = i;
    }
    for (int i = 1; i <= n; ++i) 
        if (a[i] + i <= c) {
            t = c - a[i] - i;
            cur = 0;
            sm = 0;
            bit1.update(p[i], -1);
            bit2.update(p[i], -(a[i] + min(i, n - i + 1)));
            for (int j = 17; j >= 0; --j)
                if (cur + (1 << j) <= n && sm + bit2.bit[cur + (1 << j)] <= t) {
                    cur += (1 << j);
                    sm += bit2.bit[cur + (1 << j)];
                }
            ans = max(ans, bit1.query(cur) + 1);
            bit1.update(p[i], 1);
            bit2.update(p[i], a[i] + min(i, n - i + 1));
        }
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