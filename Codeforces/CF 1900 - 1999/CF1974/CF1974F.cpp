#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

set<array<int, 2>> x, y;

void remove(int p, int q) {
    x.erase({p, q});
    y.erase({q, p});
}

void solve() {
    int a1 = 1, a2, b1 = 1, b2, n, m;
    cin >> a2 >> b2 >> n >> m;
    array<int, 2> ans = {0, 0};
    x.clear();
    y.clear();
    while (n--) {
        int p, q;
        cin >> p >> q;
        x.insert({p, q});
        y.insert({q, p});
    }
    for (int i = 0; i < m; ++i) {
        char c;
        int d;
        cin >> c >> d;
        if (c == 'U') {
            a1 += d;
            while (!x.empty()) {
                auto [p, q] = *x.begin();
                if (a1 <= p) {
                    break;
                }
                remove(p, q);
                ++ans[i & 1];
            }
        }
        else if (c == 'D') {
            a2 -= d;
            while (!x.empty()) {
                auto [p, q] = *(--x.end());
                if (p <= a2) {
                    break;
                }
                remove(p, q);
                ++ans[i & 1];
            }
        }
        else if (c == 'L') {
            b1 += d;
            while (!y.empty()) {
                auto [q, p] = *y.begin();
                if (b1 <= q) {
                    break;
                }
                remove(p, q);
                ++ans[i & 1];
            }
        }
        else {
            b2 -= d;
            while (!y.empty()) {
                auto [q, p] = *(--y.end());
                // cout << p << " " << q << "\n";
                if (q <= b2) {
                    break;
                }
                remove(p, q);
                ++ans[i & 1];
            }
        }
        // cout << a1 << " " << a2 << " " << b1 << " " << b2 << "\n";
    }
    cout << ans[0] << " " << ans[1] << "\n";
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