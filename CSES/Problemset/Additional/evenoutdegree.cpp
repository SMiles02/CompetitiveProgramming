#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 1;
int tin[N], timer;
bitset<N> deg;
vector<int> e[N];
vector<array<int, 2>> ans;
 
void direct_edge(int x, int y) {
    ans.push_back({x, y});
    deg[x] = deg[x] ^ 1;
}
 
void dfs(int c, int p = 0) {
    tin[c] = ++timer;
    for (int i : e[c])
        if (i != p) {
            if (tin[i]) {
                if (tin[i] < tin[c])
                    direct_edge(c, i);
                continue;
            }
            dfs(i, c);
            if (deg[i])
                direct_edge(i, c);
            else
                direct_edge(c, i);
        }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if (!tin[i]) {
            dfs(i);
            if (deg[i]) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    for (auto [x, y] : ans) 
        cout << x << " " << y << "\n";
    return 0;
}