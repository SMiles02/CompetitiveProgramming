#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

const int N = 2e5 + 1;
int to[N];
vector<array<int, 2>> from[N];

void add_edge(int x, int y, int t) {
    ++to[y];
    from[x].push_back({y, t});
}

void solve() {
    int n, m, last, x, ans = 0;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1)), p(n + 1, vector<int>(m + 1));
    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        from[i].clear();
        to[i] = 0;
        for (int j = 1; j <= m; ++j)
            dp[i][j] = 1;
    }
    vector<int> v = {1}, w;
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[i - 1]) {
            last = -1;
            while (!v.empty() && a[i] > a[v.back()]) {
                if (last != -1)
                    add_edge(last, v.back(), 0);
                last = v.back();
                v.pop_back();
            }
            add_edge(last, i, 1);
        }
        v.push_back(i);
    }
    while (v.size() > 1) {
        last = v.back();
        v.pop_back();
        add_edge(last, v.back(), 0);
    }
    for (int i = 1; i <= n; ++i)
        if (to[i] == 0)
            w.push_back(i);
    while (!w.empty()) {
        x = w.back();
        w.pop_back();
        for (int j = 1; j <= m; ++j)
            p[x][j] = add(p[x][j - 1], dp[x][j]);
        for (auto i : from[x]) {
            if (--to[i[0]] == 0)
                w.push_back(i[0]);
            for (int j = 1; j <= m; ++j)
                dp[i[0]][j] = mul(dp[i[0]][j], p[x][j - i[1]]);
        }
    }
    for (int j = 1; j <= m; ++j)
        ans = add(ans, dp[x][j]);
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