#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 801;
const ll INF = 1e18;
array<ll, 2> ans[N];
int a[N], cnt[N];
ll d[N][N];

struct Dijkstra {
    using S = int; // regular edge weight type, change if needed
    using T = long long; // maximum possible distance type, change if needed
    struct Edge {
        int target;
        S weight;
    };
    struct next_shortest {
        int node;
        T dist;
        bool operator<(const next_shortest& rhs) const {
            return dist > rhs.dist;
        }
    };
    int n;
    vector<vector<Edge>> e;
    Dijkstra(int n) : n(n), e(n + 1) {}
    void add_directed_edge(int x, int y, S z) {
        e[x].push_back({y, z});
    }
    void shortest_path(int src) {
        vector<T> d(n + 1, INF);
        d[src] = 0;
        priority_queue<next_shortest> pq;
        pq.push({src, 0});
        while (!pq.empty()) {
            int cur_node = pq.top().node;
            T cur_dist = pq.top().dist;
            pq.pop();
            if (cur_dist > d[cur_node])
                continue;
            for (auto i : e[cur_node])
                if (cur_dist + i.weight < d[i.target]) {
                    d[i.target] = cur_dist + i.weight;
                    pq.push({i.target, d[i.target]});
                }
        }
        for (int i = 1; i <= n; ++i)
            
        return;
    }
};

void solve() {
    int n, m, p, x, y, z;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j <= n; ++j)
            d[i][j] = INF;
        d[i][i] = 0;
        ans[i] = {INF, INF};
    }
    for (int j = 0; j < m; ++j) {
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], (ll)z);
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    ans[1] = {0, p};
    queue<int> q;
    q.push(1);
    cnt[1] = 1;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        if (--cnt[i])
            continue;
        for (int j = 1; j <= n; ++j)
            if (d[i][j] < INF) {
                ll x, y;
                if (ans[i][1] < d[i][j]) {
                    x = (d[i][j] - ans[i][1] + a[i] - 1) / a[i];
                    y = 1LL * x * a[i];
                }
                else {
                    x = 0;
                    y = 0;
                }
                if (ans[i][0] + x < ans[j][0] || (ans[i][0] + x == ans[j][0] && ans[i][1] + y - d[i][j] > ans[j][1])) {
                    ans[j] = {ans[i][0] + x, ans[i][1] + y - d[i][j]};
                    q.push(j);
                    ++cnt[j];
                }
            }
    }
    if (ans[n][0] == INF)
        ans[n][0] = -1;
    cout << ans[n][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}