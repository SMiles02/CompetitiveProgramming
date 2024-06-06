#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e3 + 4;
int d[2][N], par[N];
vector<int> e[N];

void dfs(int c, int p, int x, int h) {
    d[x][c] = h;
    par[c] = p;
    for (int i : e[c]) {
        if (i != p) {
            dfs(i, c, x, h + 1);
        }
    }
}

int find_furthest(int n, int x) {
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (d[x][i] > d[x][ans]) {
            ans = i;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int x, y, z, dis;
    dfs(1, 0, 0, 0);
    x = find_furthest(n, 0);
    dfs(x, 0, 1, 0);
    y = find_furthest(n, 1);
    dis = d[1][y];
    z = y;
    while (d[1][z] > (dis + 1) / 2) {
        z = par[z];
    }
    vector<array<int, 2>> ans;
    if (dis & 1) {
        for (int i = 1; i * 2 <= dis + 1; i += 2) {
            ans.push_back({z, i});
            ans.push_back({par[z], i});
        }
    }
    else {
        for (int i = 0; i * 2 <= dis; ++i) {
            ans.push_back({z, i});
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i[0] << " " << i[1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}