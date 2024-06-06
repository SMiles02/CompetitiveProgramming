#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    int n, cur, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    disjoint_set_union dsu(n * 2);
    vector<vector<int>> v(n * 4 + 1);
    priority_queue<int> pq;
    cur = n * 2;
    for (int i = 0; i < n * 2; ++i) {
        if (s[i] == '(') {
            v[cur].push_back(i + 1);
            pq.push(cur);
            ++cur;
        }
        else {
            --cur;
            while (pq.top() > cur) {
                v[pq.top()].clear();
                pq.pop();
            }
            for (int j : v[cur]) {
                dsu.unite(i + 1, j);
            }
            while (v[cur].size() > 1) {
                v[cur].pop_back();
            }
        }
    }
    for (int i = 1; i <= n * 2; ++i) {
        ans += dsu.find_set(i) == i;
    }
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