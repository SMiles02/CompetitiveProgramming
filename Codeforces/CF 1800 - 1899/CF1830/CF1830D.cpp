#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1;
int cnt[2];
vector<int> e[N];

void dfs(int c, int p, int x) {
    ++cnt[x];
    for (int i : e[c])
        if (i != p)
            dfs(i, c, x ^ 1);
}

void solve() {
    int n;
    cin >> n;
    cnt[0] = cnt[1] = 0;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0, 0);
    // cout << 1LL * n * (n - 1) << " " << max(cnt[0], cnt[1]) << "\n";
    cout << max(1LL * n * (n - 1) + max(cnt[0], cnt[1]), (1LL * n * (n + 1)) / 2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}