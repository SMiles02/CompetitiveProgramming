#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, INF = 1e9;
int dist[N];
bool done[N];
vector<int> e[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    while (m--) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        dist[i] = INF;
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i : e[x])
            if (d[x] + 1 < d[i]) {
                d[i] = d[x] + 1;
                q.push(i);
            }
    }

    while (!q.empty()) {
        x = q.front();
        q.pop();
        done[x] = true;
        for (int i : e[x])
            if (!done[i]) {
                dist[i] = dist[x] + 1;
                q.push(i);
            }
    }
    return 0;
}