#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int sub(int a, int b) { return add(a, MOD - b); }

void solve() {
    int n;
    cin >> n;
    int c = 1, d = 1;
    ll x = 0, y = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        // cout << "entering " << i << ": " << x << " " << y << " " << c << " " << d << "\n";
        cin >> a[i];
        ll p = 1e18, q = -1e18;
        vector<array<ll, 2>> cmb = {{x + a[i], c}, {y + a[i], d}, {abs(x + a[i]), c}, {abs(y + a[i]), d}};
        for (auto i : cmb) {
            p = min(p, i[0]);
            q = max(q, i[0]);
        }
        if (p == q) {
            x = y = p;
            c = d = mul(c, 2);
            continue;
        }
        if (x == y) {
            cmb = {{x + a[i], c}, {abs(x + a[i]), c}};
        }
        int cnt1 = 0, cnt2 = 0;
        for (auto i : cmb) {
            if (i[0] == p) {
                cnt1 = add(cnt1, i[1]);
            }
            if (i[0] == q) {
                cnt2 = add(cnt2, i[1]);
            }
        }
        x = p;
        y = q;
        c = cnt1;
        d = cnt2;
        // cout << i << ": " << x << " " << y << " " << c << " " << d << "\n";
    }
    cout << d << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}