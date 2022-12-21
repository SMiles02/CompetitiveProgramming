#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<array<int, 2>> e[N];

void dfs(int c, int p, int x, int y, vector<int>& v) {
    v[c] = x;
    for (auto i : e[c])
        if (i[0] != p && i[0] != y)
            dfs(i[0], c, x ^ i[1], y, v);
}

void solve() {
    int n, a, b, x, y, z;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    vector<int> v(n + 1, -1), w(n + 1, -1);
    dfs(a, 0, 0, b, v);
    dfs(b, 0, 0, 0, w);
    set<int> s;
    for (int i = 1; i <= n; ++i)
        if (v[i] != -1)
            s.insert(v[i]);
    for (int i = 1; i <= n; ++i)
        if (i != b && s.count(w[i])) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}