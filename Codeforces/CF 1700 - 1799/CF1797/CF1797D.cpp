#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int a[N], sub[N], p[N];
long long sm[N];
vector<int> e[N];
set<array<int, 2>> heavy[N];

void dfs(int c) {
    sub[c] = 1;
    sm[c] = a[c];
    for (auto i : e[c])
        if (i != p[c]) {
            p[i] = c;
            dfs(i);
            sub[c] += sub[i];
            sm[c] += sm[i];
            heavy[c].insert({-sub[i], i});
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1);
    while (q--) {
        int t, y;
        cin >> t >> y;
        if (t == 1)
            cout << sm[y] << "\n";
        else {
            if (heavy[y].empty())
                continue;
            int x = p[y], z = (*(heavy[y].begin()))[1];
            heavy[x].erase({-sub[y], y});
            heavy[y].erase({-sub[z], z});
            sub[y] -= sub[z];
            sub[z] += sub[y];
            sm[y] -= sm[z];
            sm[z] += sm[y];
            p[z] = x;
            p[y] = z;
            heavy[x].insert({-sub[z], z});
            heavy[z].insert({-sub[y], y});
        }
    }
    return 0;
}