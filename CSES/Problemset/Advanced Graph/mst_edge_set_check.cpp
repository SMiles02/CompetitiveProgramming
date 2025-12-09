#include <bits/stdc++.h>
using namespace std;

struct line_tree {
    int N, L;
    vector<int> head, tail, tin;
    vector<vector<array<int, 2>>> sparse_table;
    line_tree(int n) : N(n), L((int)log2(n) + 2), head(n + 1), tail(n + 1), tin(n + 1), sparse_table(L, vector<array<int, 2>>(n + 1)) {
        iota(head.begin(), head.end(), 0);
        iota(tail.begin(), tail.end(), 0);
        for (int i = 1; i <= N; ++i)
            sparse_table[0][i] = {i, 0};
    }
    int find_head(int x) {
        return x == head[x] ? x : head[x] = find_head(head[x]);
    }
    int find_tail(int x) {
        return x == tail[x] ? x : tail[x] = find_tail(tail[x]);
    }
    void unite(int x, int y, int time_of_edge) {
        int xx = x, yy = y;
        x = find_head(x);
        y = find_head(y);
        if (x != y) {
            int t = find_tail(x);
            sparse_table[0][t] = {y, time_of_edge};
            tail[t] = y;
            head[y] = x;
            cerr << xx << " " << yy << " added with edge weight " << time_of_edge << endl;
        }
    }
    void build_tree() {
        for (int j = 1; j < L; ++j)
            for (int i = 1; i <= N; ++i)
                sparse_table[j][i] = {sparse_table[j - 1][sparse_table[j - 1][i][0]][0], max(sparse_table[j - 1][i][1], sparse_table[j - 1][sparse_table[j - 1][i][0]][1])};
        vector<bool> done(N + 1);
        int timer = 0;
        for (int i = 1; i <= N; ++i)
            if (!done[i]) {
                int cur = find_head(i);
                while (!done[cur]) {
                    tin[cur] = ++timer;
                    done[cur] = true;
                    cur = sparse_table[0][cur][0];
                }
            }
    }
    int time_of_connection(int x, int y) {
        if (find_head(x) != find_head(y))
            return -1;
        if (tin[x] > tin[y])
            swap(x, y);
        int ans = 0;
        for (int i = L - 1; i >= 0; --i)
            if ((tin[y] - tin[x]) & (1 << i)) {
                ans = max(ans, sparse_table[i][x][1]);
                x = sparse_table[i][x][0];
            }
        return ans;
    }
};

struct disjoint_set_union_rollback {
    vector<int> p, sz;
    vector<array<int, 2>> changes;
    disjoint_set_union_rollback(int n) : p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int i) {
        return i == p[i] ? i : p[i] = find_set(p[i]);
    }
    bool unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            p[j] = i;
            sz[i] += sz[j];
            changes.push_back({i, j});
            return true;
        }
        return false;
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
    void roll_back() {
        int i = changes.back()[0], j = changes.back()[1];
        changes.pop_back();
        p[j] = j;
        sz[i] -= sz[j];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<array<int, 3>> edges(m), sort_edges(m);
    line_tree tree(n);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        sort_edges[i] = edges[i];
    }
    sort(sort_edges.begin(), sort_edges.end());
    for (auto [w, x, y] : sort_edges) {
        tree.unite(x, y, w);
    }
    tree.build_tree();
    disjoint_set_union_rollback dsu(n);
    while (q--) {
        bool ok = true;
        int k;
        cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; ++i) {
            cin >> v[i];
            --v[i];
            cerr << edges[v[i]][1] << " " << edges[v[i]][2] << " " << edges[v[i]][0] << "\n";
            cerr << !dsu.connected(edges[v[i]][1], edges[v[i]][2]) << " " << tree.time_of_connection(edges[v[i]][1], edges[v[i]][2]) << endl;
            ok &= dsu.unite(edges[v[i]][1], edges[v[i]][2]) && tree.time_of_connection(edges[v[i]][1], edges[v[i]][2]) == edges[v[i]][0];
        }
        while (!dsu.changes.empty()) {
            dsu.roll_back();
        }
        if (ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}