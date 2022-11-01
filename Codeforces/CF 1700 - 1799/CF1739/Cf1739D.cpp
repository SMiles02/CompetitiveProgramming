#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, L = 19;
int dp[N];
vector<int> e[N];

void dfs(int c, int d) {
    dp[c] = d;
    for (int i : e[c])
        dfs(i, d + 1);
}

void solve() {
    int n, k, x, l, r, m, cost;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        e[x].push_back(i);
    }
    dfs(1, 0);
    l = 1;
    r = n - 1;
    while (l < r) {
        m = l + (r - l) / 2;
        // cerr << m << "!\n";
        cost = 0;
        for (int i = 1; i <= n; ++i) {
            // cerr << i << " " << dp[i] << " " << (dp[i] > 1 && (max(dp[i] % m, m) == 1)) << "\n";
            cost += (dp[i] > 1 && (dp[i] % m == 1 || m == 1));
        }
        // cerr << cost << "!!\n";
        if (cost > k)
            l = m + 1;
        else
            r = m;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}