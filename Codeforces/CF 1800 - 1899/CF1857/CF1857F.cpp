#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll count(map<int, int>& m, int p, int q) {
    if (p == q) {
        return (1LL * m[p] * (m[p] - 1)) / 2;
    }
    return 1LL * m[p] * m[q];
}

void solve() {
    int n, q;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        ++m[k];
    }
    cin >> q;
    while (q--) {
        ll x, y, p, q, ans = 0;
        cin >> x >> y;
        ll a = 1, b = -x, c = y, s;
        set<array<ll, 2>> done;
        if (b * b - a * c * 4 < 0) {
            cout << "0 ";
            continue;
        }
        s = sqrt(b * b - a * c * 4);
        if (s * s != b * b - a * c * 4) {
            cout << "0 ";
            continue;
        }
        if ((-b + s) % (a * 2) == 0) {
            p = (-b + s) / (a * 2);
            q = x - p;
            if (p * q == y) {
                ans += count(m, p, q);
                done.insert({p, q});
            }
        }
        if ((-b - s) % (a * 2) == 0) {
            p = (-b - s) / (a * 2);
            q = x - p;
            if (p * q == y && done.count({p, q}) == 0 && done.count({q, p}) == 0) {
                ans += count(m, p, q);
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}