#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
const long long INF = 1e18;
vector<array<int, 2>> e[N];
long long val[N];
bool ok;

void dfs(int c) {
    for (auto& [x, d] : e[c]) {
        if (val[x] == INF) {
            val[x] = val[c] + d;
            dfs(x);
        }
        else if (val[x] != val[c] + d) {
            ok = false;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        val[i] = INF;
        e[i].clear();
    }
    while (m--) {
        int a, b, d;
        cin >> a >> b >> d;
        e[a].push_back({b, d});
        e[b].push_back({a, -d});
    }
    ok = true;
    for (int i = 1; i <= n; ++i) {
        if (val[i] == INF) {
            val[i] = 0;
            dfs(i);
        }
    }
    if (ok) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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