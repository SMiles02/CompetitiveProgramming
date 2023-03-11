#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, INF = 1e9 + 5;
int cur, scc[N], sz[N], ans;
vector<array<int, 2>> e1[N], e2[N], scc_edges[N];
vector<int> sccE[N];
stack<int> s;
set<int> exist[N];
multiset<int> flip;
bitset<N> d1, d2, d3, d4;
map<int, int> edge_weight[N];

struct DSU {
    vector<int> pt, rk;
    DSU(int n) : pt(n + 1), rk(n + 1, 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};


void dfs1(int c) {
    d1[c] = 1;
    for (auto i : e1[c])
        if (!d1[i[0]])
            dfs1(i[0]);
    s.push(c);
}

void dfs2(int c, int g) {
    cerr << c << " " << g << endl;
    scc[c] = g;
    ++sz[g];
    d2[c] = 1;
    for (auto i : e2[c])
        if (!d2[i[0]])
            dfs2(i[0], g);
}

void dfs_all_scc(int c, int p) {
    cerr << c << " " << p << "!" << endl;
    d3[c] = 1;
    for (auto i : scc_edges[c])
        if (!d3[c]) {
            if (i[1] < 0)
                flip.insert(-i[1]);
            dfs_all_scc(i[0], c);
        }
}

void dfs_calc_flip(int c, int p) {
    
}

void solve() {
    int n, m, x, y, z;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= n; ++i) {
        e1[i].clear();
        e2[i].clear();
        scc_edges[i].clear();
        sccE[i].clear();
        d1[i] = 0;
        d2[i] = 0;
        d3[i] = 0;
        d4[i] = 0;
        scc[i] = 0;
        sz[i] = 0;
        exist[i].clear();
        edge_weight[i].clear();
    }
    while (!s.empty())
        s.pop();
    cur = 0;
    ans = INF;
    flip.clear();
    flip.insert(0);
    while (m--) {
        cin >> x >> y >> z;
        e1[x].push_back({y, z});
        e2[y].push_back({x, z});
        dsu.unite(x, y);
    }
    if (dsu.rk[dsu.find_set(1)] != n) {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (!d1[i])
            dfs1(i);
    while (!s.empty()) {
        x = s.top();
        s.pop();
        if (!d2[x])
            dfs2(x, ++cur);
    }
    for (int i = 1; i <= n; ++i)
        for (auto j : e1[i])
            if (scc[i] != scc[j[0]]) {
                if (exist[scc[i]].count(scc[j[0]]) == 0) {
                    sccE[scc[i]].push_back(scc[j[0]]);
                    exist[scc[i]].insert(scc[j[0]]);
                    edge_weight[scc[i]][scc[j[0]]] = j[1];
                }
                else
                    edge_weight[scc[i]][scc[j[0]]] = min(edge_weight[scc[i]][scc[j[0]]], j[1]);
            }
    for (int i = 1; i <= cur; ++i)
        for (int j : sccE[i]) {
            scc_edges[i].push_back({j, edge_weight[i][j]});
            scc_edges[j].push_back({i, -edge_weight[i][j]});
        }
    dfs_all_scc(1, 0);

    cout << ans << "!\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}