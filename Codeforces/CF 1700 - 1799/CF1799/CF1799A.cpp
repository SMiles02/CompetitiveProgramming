#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, cur;
    cin >> n >> m;
    vector<int> ans(n + 1, -1);
    vector<bool> dn(n + m + 1, false);
    cur = n;
    for (int i = 1; i <= m; ++i) {
        cin >> k;
        if (!dn[k] && cur > 0)
            ans[cur--] = i;
        dn[k] = true;
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
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