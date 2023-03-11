#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 1, M = 2, MX = 1e9;
const ll INF = 1e18;
array<int, 2> v[N][M];
ll dp[N][M];

void solve() {
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < M; ++j) {
            v[i][j] = {MX, MX};
            dp[i][j] = INF;
        }
    v[0][0] = {0, a[0]};
    dp[0][0] = 0;
    for (int i = 1; i < n; ++i) {
        if (i == n - 1)
            v[i][0] = {a[i], 0};
        else if (s <= a[i]) {
            v[i][0] = {s, a[i] - s};
            v[i][1] = {a[i] - s, s};
        }
        else {
            v[i][0] = {0, a[i]};
            v[i][1] = {a[i], 0};
        }
        for (int j = 0; j < M; ++j)
            if (v[i][j][0] != MX)
                for (int k = 0; k < M; ++k)
                    if (v[i - 1][k][0] != MX)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1LL * v[i - 1][k][1] * v[i][j][0]);
    }
    ll ans = INF;
    for (int j = 0; j < M; ++j)
        if (dp[n - 1][j] < ans)
            ans = dp[n - 1][j];
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