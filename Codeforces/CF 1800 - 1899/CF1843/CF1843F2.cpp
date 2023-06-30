#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

// F2 is centroid decomp, don't wanna code tbh

void solve() {
    int q, n = 1;
    cin >> q;
    vector<array<int, 5>> p(q + 3);
    // {l, r, p_min, p_max, p_i}
    p[1] = {0, 1, 0, 1, 1};
    while (q--) {
        char c;
        cin >> c;
        if (c == '+') {
            int v, x;
            cin >> v >> x;
            p[++n] = {min(p[v][0], p[v][4] + x - p[v][3]), max(p[v][1], p[v][4] + x - p[v][2]), min(p[v][4] + x, p[v][2]), max(p[v][4] + x, p[v][3]), p[v][4] + x};
        }
        else {
            int u, v, k;
            cin >> u >> v >> k;
            if (p[v][0] <= k && k <= p[v][1]) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}