#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 1, INF = -1e9;
int a[N], n, m, to[N], dp[N];
ll k;
vector<int> from[N];
vector<array<int, 2>> edges;

bool check(ll x) {
    int v, good = 0, mx = 0, dn = 0;
    for (int i = 1; i <= n; ++i) {
        from[i].clear();
        to[i] = 0;
        if (a[i] <= x) {
            dp[i] = 1;
            ++good;
        }
        else
            dp[i] = INF;
    }
    for (auto i : edges)
        if (a[i[0]] <= x && a[i[1]] <= x) {
            from[i[0]].push_back(i[1]);
            ++to[i[1]];
        }
    stack<int> stk;
    for (int i = 1; i <= n; ++i)
        if (a[i] <= x && to[i] == 0)
            stk.push(i);
    while (!stk.empty()) {
        v = stk.top();
        mx = max(mx, dp[v]);
        ++dn;
        stk.pop();
        for (int i : from[v]) {
            dp[i] = dp[v] + 1;
            if (--to[i] == 0)
                stk.push(i);
        }
    }
    return (dn < good || mx >= k);
}
  
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll l = 1, r = 1e18, mid;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    edges.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> edges[i][0] >> edges[i][1];
    if (!check(r)) {
        cout << "-1\n";
        return 0;
    }
    while (l < r) {
        mid = l + (r - l) / 2;
        if (!check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << l;
    return 0;
}