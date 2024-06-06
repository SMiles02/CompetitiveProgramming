#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 80009;
const ll INF = -1e18; 
ll dp[2][N];

void solve() {
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = dp[1][i] = INF;
    }
    while (k--) {
        int m;
        cin >> m;
        vector<int> v(m);
        for (int i = 0; i < m; ++i) {
            cin >> v[i];
        }
        sort(v.rbegin(), v.rend());
        ll sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += v[i];
            if (i > 0) {
                for (int j = i + 1; j <= n; ++j) {
                    dp[1][j] = max(dp[1][j], dp[0][j - i - 1] + sum);
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = dp[1][i];
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << dp[0][i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}