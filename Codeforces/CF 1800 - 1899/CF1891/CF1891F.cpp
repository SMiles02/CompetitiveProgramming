#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct BIT {
    int n; // rtn might need to be LLed
    ll rtn;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n + 1,0) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] += d; }
    ll query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit[i];
        return rtn;
    }
    ll query(ll x, ll y) { return query(y) - query(x - 1); }
};

const int N = 5e5 + 1;
int tin[N], tout[N], timer;
vector<int> e[N];

void dfs(int c) {
    tin[c] = timer++;
    for (int i : e[c]) {
        dfs(i);
    }
    tout[c] = timer;
}

void solve() {
    int n = 1, q, cur_nodes;
    cin >> q;
    vector<array<int, 3>> queries(q);
    for (auto &[t, x, y] : queries) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            ++n;
            e[x].push_back(n);
        }
        else {
            cin >> x >> y;
        }
    }
    vector<ll> ans(n + 1);
    BIT bit(n);
    timer = 1;
    dfs(1);
    cur_nodes = n;
    for (int i = q - 1; i >= 0; --i) {
        auto [t, x, y] = queries[i];
        if (t == 1) {
            ans[cur_nodes] = bit.query(tin[cur_nodes]);
            --cur_nodes;
        }
        else {
            bit.update(tin[x], y);
            bit.update(tout[x], -y);
        }
    }
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    ans[1] = bit.query(1);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}