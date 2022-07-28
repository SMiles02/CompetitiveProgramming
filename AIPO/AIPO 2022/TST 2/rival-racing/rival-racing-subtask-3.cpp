#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, INF = 1e9;
int n;
set<int> vis[N];
vector<array<int, 2>> e[N];
bitset<N> is_special;

struct city_distance {
    int city;
    int source;
    int dist;
    bool operator<(const city_distance& rhs) const {
        return dist > rhs.dist;
    }
};

int dijkstra(vector<int> sources) {
    priority_queue<city_distance> pq;
    for (int i : sources)
        pq.push({i, i, 0});
    while (!pq.empty()) {
        city_distance cur = pq.top();
        pq.pop();
        if (vis[cur.city].count(cur.source))
            continue;
        vis[cur.city].insert(cur.source);
        if (vis[cur.city].size() == 2 && is_special[cur.city])
            return cur.dist;
        for (auto i : e[cur.city])
            if (!vis[i[0]].count(cur.source))
                pq.push({i[0], cur.source, cur.dist + i[1]});
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, k, x, y, z, ans = INF;
    cin >> n >> m >> k;
    while (m--) {
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    vector<int> special;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        if (x > 2) {
            is_special[x] = 1;
            special.push_back(x);
        }
    }
    cout << dijkstra(special) + 1 << "\n";
    return 0;
}