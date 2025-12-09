#include <bits/stdc++.h>
using namespace std;

struct fenwick_tree {
    int n;
    vector<int> bit;
    fenwick_tree(int n) : n(n), bit(n + 1) {}
    void update(int x, int d) {
        for (int i = x; i <= n; i += i & -i) {
            bit[i] += d;
        }
    }
    int query(int x) {
        int sum = 0;
        for (int i = x; i; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }
    int query(int x, int y) {
        if (y <= 0) {
            return 0;
        }
        return query(y) - query(max(x - 1, 0));
    }
};


const int N = 2e5 + 1;
vector<int> e[N];
int l, r, sub[N], max_modified;
long long ans;
bitset<N> black;
fenwick_tree dp(N);

void sub_dfs(int c, int p) {
    sub[c] = 1;
    for (int i : e[c]) {
        if (i != p && !black[i]) {
            sub_dfs(i, c);
            sub[c] += sub[i];
        }
    }
}

int find_centroid(int c, int p, int tree_size) {
    for (int i : e[c]) {
        if (i == p || black[i]) continue;
        if (sub[i] * 2 > tree_size) {
            return find_centroid(i, c, tree_size);
        }
    }
    return c;
}

void dfs(int c, int p, int h, bool update_dp) {
    if (!update_dp) {
        ans += dp.query(l - h + 1, r - h + 1);
    }
    else {
        max_modified = max(max_modified, h + 1);
        dp.update(h + 1, update_dp);
    }
    for (int i : e[c]) {
        if (i != p && !black[i]) {
            dfs(i, c, h + 1, update_dp);
        }
    }
}

void solve(int c) {
    sub_dfs(c, -1);
    int centroid = find_centroid(c, -1, sub[c]);
    black[centroid] = 1;
    max_modified = 1;
    dp.update(1, 1);
    for (int i : e[centroid]) {
        if (!black[i]) {
            dfs(i, centroid, 1, false);
            dfs(i, centroid, 1, true);
        }
    }
    for (int i = 1; i <= max_modified; ++i) {
        dp.update(i, -dp.bit[i]);
    }
    for (int i : e[centroid]) {
        if (!black[i]) {
            solve(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n >> l >> r;
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    solve(1);
    cout << ans;
    return 0;
}