#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1, K = 21;
const long long INF = 1e18;
vector<int> e[N];
long long a[N], dp[N][K];

void dfs(int c, int p) {
    for (int x : e[c]) {
        if (x != p) {
            dfs(x, c);
        }
    }
    for (int i = 1; i < K; ++i) {
        dp[c][i] = a[c] * i;
        for (int x : e[c]) {
            if (x == p) {
                continue;
            }
            long long mini = INF;
            for (int j = 1; j < K; ++j) {
                if (i != j) {
                    mini = min(mini, dp[x][j]);
                }
            }
            dp[c][i] += mini;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        cin >> a[i];
    }
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    long long ans = INF;
    for (int i = 1; i < K; ++i) {
        ans = min(ans, dp[1][i]);
    }
    cout << ans << "\n";
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