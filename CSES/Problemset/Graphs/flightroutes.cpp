#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node_dist {
    int node;
    ll dist;
    bool operator<(const node_dist& rhs) const {
        return dist > rhs.dist;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 2>>> e(n + 1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
    }
    vector<vector<ll>> d(n + 1);
    vector<int> cnt(n + 1);
    priority_queue<node_dist> pq;
    pq.push({1, 0});
    while (!pq.empty()) {
        int x = pq.top().node;
        ll y = pq.top().dist;
        pq.pop();
        if (cnt[x]++ > k)
            continue;
        for (auto i : e[x])
            if (cnt[i[0]] < k && (d[i[0]].size() < k || y + i[1] < d[i[0]].back())) {
                d[i[0]].push_back(y + i[1]);
                sort(d[i[0]].begin(), d[i[0]].end());
                if (d[i[0]].size() > k)
                    d[i[0]].pop_back();
                pq.push({i[0], y + i[1]});
            }
    }
    for (auto i : d[n])
        cout << i << " ";
    return 0;
}