#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;
int nV[N], eV[N], n;
vector<array<int, 2>> e[N];

void dfs(int c, int p, int h) {
    for (auto i : e[c])
        if (i[0] != p) {
            if (h & 1) {
                eV[i[1]] = i[0];
                nV[i[0]] = i[0] ^ n;
            }
            else {
                eV[i[1]] = i[0] ^ n;
                nV[i[0]] = i[0];
            }
            dfs(i[0], c, h ^ 1);
        }
}

void solve() {
    int p, x, y;
    cin >> p;
    n = 1 << p;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back({y, i});
        e[y].push_back({x, i});
    }
    nV[n] = n;
    dfs(n, 0, 0);
    cout << n << "\n";
    for (int i = 1; i <= n; ++i)
        cout << nV[i] << " ";
    cout << "\n";
    for (int i = 1; i < n; ++i)
        cout << eV[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}