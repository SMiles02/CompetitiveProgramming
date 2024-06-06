#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct disjoint_set_union {
    vector<int> p, sz;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int i) {
        return i == p[i] ? i : p[i] = find_set(p[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            p[j] = i;
            sz[i] += sz[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

const ll INF = 1e18;

void solve() {
    int n, m, k;
    ll ans;
    cin >> n >> m >> k;
    disjoint_set_union dsu(n);
    vector<vector<int>> from(n + 1), head(n + 1);
    vector<int> h(n + 1);
    vector<ll> dp(n + 1), dp2(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        dp[i] = h[i];
    }
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        dsu.unite(a, b);
        from[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) {
        head[dsu.find_set(i)].push_back(i);
        for (int j : from[i]) {
            if (h[i] <= h[j]) {
                dp[j] = max(dp[j], dp[i] + h[j] - h[i]);
            }
            else {
                dp[j] = max(dp[j], dp[i] + k + h[j] - h[i]);
            }
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    vector<array<ll, 2>> cmp;
    multiset<ll> mini;
    multiset<ll, greater<ll>> maxi;
    for (int i = n; i >= 1; --i) {
        if (!from[i].empty()) {
            dp[i] = INF;
            dp2[i] = 0;
            for (int j : from[i]) {
                dp2[i] = max(dp2[i], dp2[j]);
                if (h[i] <= h[j]) {
                    dp[i] = min(dp[i], dp[j] - h[j] + h[i]);
                }
                else {
                    dp[i] = min(dp[i], dp[j] - h[j] + h[i] - k);
                }
            }
        }
        else {
            dp2[i] = dp[i];
        }
        cmp.push_back({dp[i], dp2[i]});
        mini.insert(dp[i]);
        maxi.insert(dp2[i]);
        // cout << i << ": " << dp[i] << " " << dp2[i] << "\n";
        // cerr << i << ": " << dsu.find_set(i) << "\n";
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    ans = *maxi.begin() - *mini.begin();
    sort(cmp.begin(), cmp.end());
    for (auto i : cmp) {
        mini.erase(mini.find(i[0]));
        mini.insert(i[0] + k);
        maxi.erase(maxi.find(i[1]));
        maxi.insert(i[1] + k);
        ans = min(ans, *maxi.begin() - *mini.begin());
    }
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