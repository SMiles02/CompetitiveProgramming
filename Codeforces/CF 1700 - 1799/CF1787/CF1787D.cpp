#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n, a[N], sub[N], good_cnt;
vector<int> e[N];
bitset<N> on_path;

void dfs(int c) {
    sub[c] = 1;
    ++good_cnt;
    for (int i : e[c]) {
        dfs(i);
        sub[c] += sub[i];
    }
}

void solve() {
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        on_path[i] = 0;
        sub[i] = 0;
    }
    good_cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (1 <= i + a[i] && i + a[i] <= n)
            e[i + a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if (i + a[i] < 1 || n < i + a[i])
            dfs(i);
    for (int i = 1; 1 <= i && i <= n && on_path[i] == 0; i += a[i])
        on_path[i] = 1;
    if (sub[1]) {
        for (int i = 1; i <= n; ++i) {
            if (on_path[i])
                ans += n + 1 + good_cnt - sub[i];
            else
                ans += n * 2 + 1;
        }
    }
    else {
        for (int i = 1; i <= n; ++i)
            if (on_path[i])
                ans += n + 1 + good_cnt;
    }
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