#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5 + 1, S = 315;

void solve() {
    int n, q, x, y;
    cin >> n >> q;
    vector<int> a(n + 1), p(n + 1);
    vector<map<int, array<ll, 3>>> m(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 2; i <= n; ++i)
        cin >> p[i];
    while (q--) {
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        int c = x, d = y, ups = 0;
        ll ans = 0, cur = 0;
        while (x > 0) {
            // cerr << x << " " << y << "!" << endl;
            if (m[x].find(y) == m[x].end()) {
                ans += 1LL * a[x] * a[y];
                cur += 1LL * a[x] * a[y];
                x = p[x];
                y = p[y];
            }
            else {
                array<ll, 3> tmp = m[x][y];
                x = tmp[0];
                y = tmp[1];
                ans += tmp[2];
                cur += tmp[2];
            }
            if (x > y)
                swap(x, y);
            ++ups;
            if (ups == S) {
                m[c][d] = {x, y, cur};
                c = x;
                d = y;
                ups = 0;
                cur = 0;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}