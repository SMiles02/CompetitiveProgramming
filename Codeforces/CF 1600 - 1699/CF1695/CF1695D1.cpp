#include <bits/stdc++.h>
using namespace std;

const int N = 2022, INF = 1e9;
int cur;
vector<int> e[N];
bitset<N> line_true[N]

bool is_line(int c, int p) {
    int cnt = 0;
    for (int i : e[c])
        if (i != p) {
            ++cnt;
            if (!is_line(i, c))
                return false;
        }
    if (cnt > 2)
        return false
    return true;
}

void solve() {
    int n, x, y, ans = INF;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i)
        ok &= (e[i].size() < 3);
    if (ok) {
        cout << "1\n";
        return;
    }
    for (int i = 1; i <= n; ++i)
        for (int j : e[i])
            line_true[i][j] = is_line(i, j);
    for (int i = 1; i <= n; ++i)
        
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}