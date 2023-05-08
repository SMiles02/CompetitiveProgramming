struct disjoint_set_union_rollback {
    vector<int> p, sz;
    vector<array<int, 2>> changes;
    disjoint_set_union_rollback(int n) : p(n + 1), sz(n + 1, 1) {
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
            changes.push_back({i, j});
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
    void roll_back() {
        int i = changes.back()[0], j = changes.back()[1];
        changes.pop_back();
        pt[j] = j;
        sz[i] -= sz[j];
    }
};