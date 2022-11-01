#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;

const int N = 1005, MOD = 998244353;
int a[N], to[N];
vector<int> from[N];
vector<array<ll, 2>> v[N], w[N];

void solve() {
    int n, m, x, y;
    ll ans = 0, last, b;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        to[i] = 0;
        from[i].clear();
        v[i].clear();
        w[i].clear();
    }
    while (m--) {
        cin >> x >> y;
        from[x].push_back(y);
        ++to[y];
    }
    vector<int> topo;
    for (int i = 1; i <= n; ++i)
        if (to[i] == 0)
            topo.push_back(i);
    for (int i = 0; i < topo.size(); ++i)
        for (int j : from[topo[i]])
            if (--to[j] == 0)
                topo.push_back(j);
    for (int i : topo) {
        // cout << i << ":\n";
        if (a[i] > 0)
            v[i].push_back({1, a[i]});
        sort(v[i].begin(), v[i].end());
        // cout << v[i].size() << "!\n";
        last = -1;
        // cerr << i << ":\n";
        // for (auto j : v[i])
        //     cerr << j[0] << " " << j[1] << "\n";
        for (int j = 0; j < v[i].size(); ++j)
            if (last < v[i][j][0]) {
                b = v[i][j][1];
                for (int k = j + 1; k < v[i].size(); ++k)
                    if (b >= v[i][k][0])
                        b += v[i][k][1] - v[i][k][0] + 1;
                w[i].push_back({v[i][j][0], b});
                last = max(last, b);
                // cout << v[i][j][0] << " " << b << " !\n";
            }
        for (int k = 0; k < w[i].size(); ++k) {
            ++w[i][k][0];
            ans = max(ans, {w[i][k][1]++});
        }
        for (int j : from[i])
            for (auto k : w[i])
                v[j].push_back(k);
    }
    cout << ans % MOD << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}