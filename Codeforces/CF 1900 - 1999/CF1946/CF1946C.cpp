#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5 + 2;
int n, m, k, dp[N], sub[N];
vector<int> e[N];

void dfs(int c, int p) {
    sub[c] = 1;
    dp[c] = 0;
    for (int i : e[c]) {
        if (i == p) {
            continue;
        }
        dfs(i, c);
        sub[c] += sub[i];
        dp[c] += dp[i];
    }
    if (sub[c] >= m) {
        sub[c] = 0;
        ++dp[c];
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int l = 0, r = n;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        dfs(1, 0);
        if (dp[1] - 1 < k) {
            r = m - 1;
        }
        else {
            l = m;
        }
    }
    cout << l << "\n";
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