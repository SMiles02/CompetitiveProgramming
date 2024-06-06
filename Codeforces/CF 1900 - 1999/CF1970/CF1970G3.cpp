#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 3, M = 5e5 + 3;
const ll INF = 1e18;
int n, tin[N], low[N], sub[N], timer;
vector<int> e[N], bridges[N];

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

struct knapsack {
    int n;
    vector<ll> dp;
    knapsack(int n) : n(n), dp(n + 1) {
        dp[0] = 1;
    }
    void add_element(int w) {
        for (int i = n; i >= w; --i) {
            dp[i] += dp[i - w];
        }
    }
    void add_element(int w, int f) {
        for (int i = 0; (1 << i) <= f; ++i) {
            add_element(w * (1 << i));
            f -= 1 << i;
        }
        if (f > 0) {
            add_element(w * f);
        }
    }
    void remove_element(int w) {
        for (int i = w; i <= n; ++i) {
            dp[i] -= dp[i - w];
        }
    }
    bool check_possible(int w) {
        return dp[w] > 0;
    }
};

void dfs(int c, int p, int sz) {
    tin[c] = low[c] = ++timer;
    ++sub[c];
    for (int i : e[c]) {
        if (i == p) {
            continue;
        }
        if (tin[i] != -1) {
            low[c] = min(low[c], tin[i]);
        }
        else {
            dfs(i, c, sz);
            sub[c] += sub[i];
            low[c] = min(low[c], low[i]);
            if (tin[c] < low[i]) {
                bridges[sz].push_back(sub[i]);
            }
        }
    }
}

ll f(int x) {
    return 1LL * x * x + 1LL * (n - x) * (n - x);
}

void solve() {
    int m, c, comp_cnt = 0;
    ll ans = INF;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        bridges[i].clear();
        tin[i] = -1;
        sub[i] = 0;
    }
    disjoint_set_union dsu(n);
    knapsack comps(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        dsu.unite(x, y);
    }
    // corridor doesn't already exist
    vector<int> comp_sizes(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (dsu.find_set(i) == i) {
            ++comp_cnt;
            ++comp_sizes[dsu.sz[i]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        comps.add_element(i, comp_sizes[i]);
    }
    for (int i = 1; i < n; ++i) {
        if (comps.check_possible(i)) {
            ans = min(ans, 1LL * c * (comp_cnt - 1) + f(i));
        }
    }
    // corridor already exists
    for (int i = 1; i <= n; ++i) {
        if (dsu.find_set(i) == i) {
            dfs(i, 0, dsu.sz[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (bridges[i].empty()) {
            continue;
        }
        int last, tmp = comp_sizes[i];
        for (int j = 0; (1 << j) <= tmp; ++j) {
            tmp -= 1 << j;
            last = 1 << j;
        }
        if (tmp > 0) {
            last = tmp;
        }
        comps.remove_element(i * last);
        if (last > 1) {
            comps.add_element(i * (last - 1));
        }
        sort(bridges[i].rbegin(), bridges[i].rend());
        int ptr = 0;
        for (int j = 0; j <= n; ++j) {
            if (comps.check_possible(j)) {
                while (ptr + 1 < bridges[i].size() && f(bridges[i][ptr] + j) > f(bridges[i][ptr + 1] + j)) {
                    ans = min(ans, 1LL * c * (comp_cnt - 1) + f(bridges[i][ptr++] + j));
                }
                ans = min(ans, 1LL * c * (comp_cnt - 1) + f(bridges[i][ptr] + j));
            }
        }
        if (last > 1) {
            comps.remove_element(i * (last - 1));
        }
        comps.add_element(i * last);
    }
    if (ans == INF) {
        ans = -1;
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