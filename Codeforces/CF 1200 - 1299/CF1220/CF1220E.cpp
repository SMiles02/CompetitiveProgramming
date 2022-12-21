#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
long long p[N], q[N], mx, ans;
set<int> e[N];
bitset<N> black;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, s, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    while (m--) {
        cin >> x >> y;
        e[x].insert(y);
        e[y].insert(x);
    }
    cin >> s;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        if (e[i].size() == 1 && i != s)
            v.push_back(i);
    while (!v.empty()) {
        x = v.back();
        v.pop_back();
        black[x] = 1;
        y = *e[x].begin();
        e[y].erase(x);
        q[y] = max(q[y], p[x] + q[x]);
        if (e[y].size() == 1 && y != s)
            v.push_back(y);
    }
    for (int i = 1; i <= n; ++i)
        if (!black[i]) {
            ans += p[i];
            mx = max(mx, q[i]);
        }
    cout << ans + mx;
    return 0;
}