#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, L = 20; // L = log2(N) + 3
int n, cmp[N], tin[N * 4], tout[N * 4], low[N], t, up[20][N * 4];
vector<array<int, 2>> e[N];
vector<int> bctE[N * 4];
bitset<N * 4> d1, d2, d3;
set<int> s[N];

void dfs(int c, int p, int k) {
    d1[c] = 1;
    cmp[c] = k;
    tin[c] = low[c] = ++t;
    for (auto i : e[c])
        if (i[1] != p) {
            if (d1[i[0]])
                low[c] = min(low[c], tin[i[0]]);
            else {
                dfs(i[0], i[1], k);
                low[c] = min(low[c], low[i[0]]);
                if (tin[c] < low[i[0]]) {
                    s[c].insert(i[0]);
                    s[i[0]].insert(c);
                }
            }
        }
}

void build(int c, int g) {
    d2[c] = 1;
    bctE[c].push_back(g);
    bctE[g].push_back(c);
    for (auto i : e[c])
        if (!d2[i[0]]) {
            if (s[c].count(i[0])) {
                bctE[c].push_back(i[0]);
                bctE[i[0]].push_back(c);
                build(i[0], ++t);
            }
            else
                build(i[0], g);
        }
}

void bctDfs(int c, int p) {
    d3[c] = 1;
    up[0][c] = p;
    for (int i = 1; i < L; ++i)
        up[i][c] = up[i - 1][up[i - 1][c]];
    tin[c] = ++t;
    for (int i : bctE[c])
        if (i != p)
            bctDfs(i, c);
    tout[c] = ++t;
}

bool isAncestor(int x, int y) {
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y) {
    if (isAncestor(x, y))
        return x;
    if (isAncestor(y, x))
        return y;
    for (int i = L - 1; i >= 0; --i)
        if (!isAncestor(up[i][x], y))
            x = up[i][x];
    return up[0][x];
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        e[x].push_back({y, i});
        e[y].push_back({x, i});
    }
    for (int i = 1;i <= n; ++i)
        if (!d1[i])
            dfs(i, -1, i);
    t = n;
    for (int i = 1; i <= n; ++i)
        if (!d2[i])
            build(i, ++t);
    t = 0;
    for (int i = 1; i <= n; ++i)
        if (!d3[i])
            bctDfs(i,0);
    tout[0] = ++t;
    return 0;
}
