#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x = 0, y = 0, ans = 0;
    cin >> n >> m;
    vector<int> p(m + 2);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (k == -1)
            ++x;
        else if (k == -2)
            ++y;
        else
            p[k] = 1;
    }
    for (int i = 1; i <= m + 1; ++i)
        p[i] = p[i] + p[i - 1];
    for (int i = 1; i <= m; ++i)
        if (p[i] > p[i - 1])
            ans = max(ans, min(i - 1, p[i - 1] + x) + min(m - i, p[m] - p[i] + y) + 1);
    if (p[1] == p[0] && y > 0)
        ans = max(ans, min(m, p[m] + y));
    if (p[m] == p[m - 1] && x > 0)
        ans = max(ans, min(m, p[m] + x));
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