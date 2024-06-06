#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5 + 3;
const ll INF = 1e15;
int a[N];
ll dp[N][11];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = INF;
        }
        int curm = 1e9;
        for (int j = 0; j <= k && 0 < i - j; ++j) {
            curm = min(a[i - j], curm);
            for (int x = 0; x + j <= k; ++x) {
                dp[i][x + j] = min(dp[i][x + j], dp[i - j - 1][x] + 1LL * curm * (j + 1));
            }
        }
    }
    cout << dp[n][k] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}