#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n, m, cur = 0, ans = INF;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            cur += 1 << i;
        }
    }
    if (cur == 0) {
        ans = 0;
    }
    vector<int> dp(1024, INF);
    dp[cur] = 0;
    array<int, 3> a[m];
    for (int i = 0; i < m; ++i) {
        string p, q;
        cin >> a[i][0];
        cin >> p;
        cin >> q;
        // cout << a[i][0] << " " << p << " " << q << "\n";
        cur = 0;
        for (int j = 0; j < n; ++j) {
            if (p[j] == '0') {
                cur += 1 << j;
            }
        }
        a[i][1] = cur;
        cur = 0;
        for (int j = 0; j < n; ++j) {
            if (q[j] == '1') {
                cur += 1 << j;
            }
        }
        a[i][2] = cur;
    }
    for (int iter = 0; iter < 20; ++iter) {
        vector<int> new_dp(1024, INF);
        for (int i = 0; i < 1024; ++i) {
            if (dp[i] < INF) {
                for (int j = 0; j < m; ++j) {
                    new_dp[(i & a[j][1]) | a[j][2]] = min(new_dp[(i & a[j][1]) | a[j][2]], dp[i] + a[j][0]);
                }
            }
        }
        if (new_dp[0] < INF) {
            ans = min(ans, new_dp[0]);
        }
        swap(new_dp, dp);
    }
    if (ans == INF) {
        ans = -1;
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