#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    vector<int> p, sz, e;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1), e(n + 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int i) {
        return i == p[i] ? i : p[i] = find_set(p[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        ++e[i];
        if (i != j) {
            if (sz[i] < sz[j]) {
                swap(i, j);
            }
            p[j] = i;
            sz[i] += sz[j];
            e[i] += e[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

struct coordinate_compression {
    vector<array<int, 2>> compress;
    coordinate_compression(vector<int> v) {
        sort(v.begin(), v.end());
        int cnt = 0;
        for (auto i : v) {
            if (compress.empty() || i != compress.back()[0]) {
                compress.push_back({i, cnt++});
            }
        }
    }
    int get_compress(int x) {
        int l = 0, r = compress.size() - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (compress[m][0] < x) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return compress[l][1];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> v;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        v.push_back(a[i][0]);
        v.push_back(a[i][1]);
    }
    coordinate_compression compress(v);
    disjoint_set_union dsu(n * 2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = compress.get_compress(a[i][j]);
        }
        dsu.unite(a[i][0], a[i][1]);
    }
    vector<vector<int>> alln(n * 2);
    for (int i = 0; i < n * 2; ++i) {
        alln[dsu.find_set(i)].push_back(i);
    }
    for (int i = 0; i < n * 2; ++i) {
        if (alln[i].empty()) {
            continue;
        }
        if (dsu.e[i] > dsu.sz[i]) {
            cout << "-1\n";
            return 0;
        }
        sort(alln[i].begin(), alln[i].end());
        if (dsu.e[i] == dsu.sz[i]) {
            ans = max(ans, alln[i].back());
        }
        else if (dsu.sz[i] > 1) {
            ans = max(ans, alln[i][alln[i].size() - 2]);
        }
    }
    cout << compress.compress[ans][0];
    return 0;
}