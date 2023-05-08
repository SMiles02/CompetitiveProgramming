#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 5005, M = 505;
int a[N], r[M][N], p[M][N];
ll dp[N];
array<int, 2> s[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    ll ans = 0;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i] = {0, i};
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> r[i][j];
            p[i][r[i][j]] = 1;
        }
        for (int j = 1; j <= n; ++j)
            p[i][j] += p[i][j - 1];
        for (int j = 0; j < n; ++j) {
            r[i][j] = p[i][r[i][j]];
            s[j][0] += r[i][j];
        }
    }
    sort(s, s + n);
    for (int i = 0; i < n; ++i) {
        dp[s[i][1]] = a[s[i][1]];
        // cout << s[i][1] << ": " << s[i][0] << "\n";
        for (int j = 0; s[j][0] + m <= s[i][0]; ++j) {
            bool ok = true;
            for (int k = 0; k < m; ++k)
                if (r[k][s[j][1]] >= r[k][s[i][1]]) {
                    ok = false;
                    break;
                }
            // cout << s[i][1] << " " << s[j][1] << "\n";
            if (ok)
                dp[s[i][1]] = max(dp[s[i][1]], dp[s[j][1]] + a[s[i][1]]);
        }
        ans = max(ans, dp[s[i][1]]);
    }
    cout << ans << "\n";
    return 0;
}