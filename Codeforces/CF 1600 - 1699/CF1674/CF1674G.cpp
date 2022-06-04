#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int toCnt[N], dp[N];
vector<int> from[N], to[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y, ans = 1;
    cin >> n >> m;
    vector<int> topo;
    while (m--) {
        cin >> x >> y;
        from[x].push_back(y);
        to[y].push_back(x);
        ++toCnt[y];
    }
    for (int i = 1; i <= n; ++i)
        if (toCnt[i] == 0)
            topo.push_back(i);
    for (int i = 0; i < topo.size(); ++i) {
        x = topo[i];
        for (int i : from[x])
            if (--toCnt[i] == 0)
                topo.push_back(i);
        dp[x] = 1;
        for (int i : to[x])
            if (from[i].size() > 1 && to[x].size() > 1)
                dp[x] = max(dp[x], dp[i] + 1);
        ans = max(ans, dp[x]);
    }
    cout << ans;
    return 0;
}