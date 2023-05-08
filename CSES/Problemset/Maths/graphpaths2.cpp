#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 101, L = 30;
const ll INF = 1e18 + 69;
ll up[L][N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int p = 0; p < L; ++p)
        for (int x = 1; x <= n; ++x)
            for (int y = 1; y <= n; ++y)
                up[p][x][y] = INF;
    while (m--) {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        up[0][x][y] = min(up[0][x][y], z);
    }
    for (int p = 1; p < L; ++p)
        for (int x = 1; x <= n; ++x)
            for (int y = 1; y <= n; ++y)
                for (int z = 1; z <= n; ++z)
                    up[p][x][y] = min(up[p][x][y], up[p - 1][x][z] + up[p - 1][z][y]);   
    vector<ll> dp(n + 1, INF);
    dp[1] = 0;
    for (int p = 0; p < L; ++p)
        if ((1 << p) & k) {
            vector<ll> new_dp(n + 1, INF);
            for (int x = 1; x <= n; ++x)
                for (int y = 1; y <= n; ++y)
                    new_dp[y] = min(new_dp[y], dp[x] + up[p][x][y]);
            swap(dp, new_dp);
        }
    if (dp[n] == INF)
        dp[n] = -1;
    cout << dp[n];
    return 0;
}