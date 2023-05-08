#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int a[N];
vector<int> e[N];
queue<int> q;

struct DSU {
    vector<int> pt, sz;
    vector<set<array<int, 2>>> s;
    vector<priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>> pq;
    DSU(int n) : pt(n + 1), sz(n + 1), pq(n + 1) {
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
            if (sz[i] < sz[j])
                swap(i, j);
            pt[j] = i;
            sz[i] += sz[j];
            while (!pq[j].empty()) {
                pq[i].push(pq[j].top());
                pq[j].pop();
            }
        }
    }
    void check(int x) {
        x = find_set(x);
        while (!pq[x].empty()) {
            int y = pq[x].top()[1], c = pq[x].top()[0];
            pq[x].pop();
            if (sz[find_set(y)] > 0)
                unite(x, y);
            else if (sz[x] >= c) {
                sz[y] = 1;
                unite(x, y);
                q.push(y);
            }
            else {
                pq[x].push({c, y});
                break;
            }
            x = find_set(x);
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        e[i].clear();
        if (a[i] == 0) {
            q.push(i);
            dsu.sz[i] = 1;
        }
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y : e[x])
            if (dsu.find_set(x) != dsu.find_set(y))
                dsu.pq[dsu.find_set(x)].push({a[y], y});
        dsu.check(x);
    }
    if (dsu.sz[dsu.find_set(1)] == n)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}