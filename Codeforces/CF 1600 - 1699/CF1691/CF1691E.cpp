#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> pt,rk;
    DSU(int n) : pt(n+1), rk(n+1, 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find(int i) {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
};

void solve() {
    int n, ans = 0;
    cin >> n;
    DSU dsu(n);
    map<int, vector<array<int, 3>>> m;
    set<int> s;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq[2];
    int a[n + 1][3];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
        s.insert(a[i][1]);
        s.insert(a[i][2] + 1);
        m[a[i][1]].push_back({a[i][0], a[i][2], i});
    }
    for (int i : s) {
        for (auto j : m[i])
            pq[j[0]].push({j[1], j[2]});
        for (int j = 0; j < 2; ++j)
            while (!pq[j].empty() && pq[j].top()[0] < i)
                pq[j].pop();
        for (int j = 0; j < 2; ++j) {
            while (min(pq[0].size(), pq[1].size()) > 0 && pq[j].size() > 1) {
                dsu.unite(pq[0].top()[1], pq[1].top()[1]);
                pq[j].pop();
            }
        }
        if (min(pq[0].size(), pq[1].size()) > 0)
            dsu.unite(pq[0].top()[1], pq[1].top()[1]);
    }
    for (int i = 1; i <= n; ++i)
        ans += (dsu.find(i) == i);
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