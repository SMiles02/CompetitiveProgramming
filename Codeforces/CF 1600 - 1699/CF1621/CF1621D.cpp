#include <bits/stdc++.h>
using namespace std;

const int N = 250 * 2;
int g[N][N];

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n * 2; ++i)
        for (int j = 0; j < n * 2; ++j)
            cin >> g[i][j];
    for (int i = n; i < n * 2; ++i)
        for (int j = n ; j < n * 2; ++j)
            ans += g[i][j];
    cout << ans + min({g[0][n], g[0][n*2-1], g[n-1][n], g[n-1][n*2-1], g[n][0], g[n*2-1][0], g[n][n-1], g[n*2-1][n-1]}) << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}