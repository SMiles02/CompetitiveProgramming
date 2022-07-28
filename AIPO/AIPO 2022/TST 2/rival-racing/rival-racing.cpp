#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, INF = 1e9;
int n;
vector<array<int, 2>> e[N];
bitset<N> is_special;

struct city_distance {
    int city, source, dist;
    bool operator<(const city_distance& rhs) const {
        return dist > rhs.dist;
    }
};

vector<city_distance> dijkstra(vector<int> sources, int threshold, int cnt) {
    priority_queue<city_distance> pq;
    vector<city_distance> v;
    vector<set<int>> vis(n + 1);
    for (int i : sources)
        pq.push({i, i, 0});
    while (!pq.empty()) {
        city_distance cur = pq.top();
        pq.pop();
        if (vis[cur.city].count(cur.source))
            continue;
        vis[cur.city].insert(cur.source);
        if (vis[cur.city].size() == cnt && is_special[cur.city]) {
            v.push_back(cur);
            if (v.size() == threshold)
                return v;
        }
        for (auto i : e[cur.city])
            if (!vis[i[0]].count(cur.source))
                pq.push({i[0], cur.source, cur.dist + i[1]});
    }
    return v;
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
    vector<int> special(k), new_special;
    for (int i = 0; i < k; ++i) {
        cin >> special[i];
        is_special[special[i]] = 1;
    }
    city_distance close_pair = dijkstra(special, 1, 2)[0];
    x = close_pair.city;
    y = close_pair.source;
    is_special[x] = 0;
    is_special[y] = 0;

    // Let a = x, and b = y, finding optimal c, d
    for (int i : special)
        if (i != x && i != y)
            new_special.push_back(i);
    vector<city_distance> other_close_pair = dijkstra(new_special, 1, 2);
    if (!other_close_pair.empty())
        ans = min(ans, close_pair.dist + other_close_pair[0].dist);

    // Let a = x and c = y, finding optimal b, d
    vector<city_distance> x_close, y_close;
    x_close = dijkstra({x}, 2, 1);
    y_close = dijkstra({y}, 2, 1);
    for (int i = 0; i < x_close.size(); ++i)
        for (int j = 0; j < y_close.size(); ++j)
            if (x_close[i].city != y_close[j].city)
                ans = min(ans, x_close[i].dist + y_close[j].dist);

    cout << ans;
    return 0;
}