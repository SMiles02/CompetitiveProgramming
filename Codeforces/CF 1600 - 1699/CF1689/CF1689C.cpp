#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;
int sub[N], dp[N];
vector<int> e[N];

void dfs(int c, int p) {
    sub[c] = 1;
    vector<int> v;
    for (int i : e[c])
        if (i != p) {
            dfs(i, c);
            v.push_back(i);
            sub[c] += sub[i];
        }
    if (v.empty())
        dp[c] = 0;
    else if (v.size() == 1)
        dp[c] = sub[c] - 2;
    else
        dp[c] = max(dp[v[0]] + sub[v[1]] - 1, dp[v[1]] + sub[v[0]] - 1);
}

void solve() {
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    cout << dp[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}