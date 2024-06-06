#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2005;
const ll INF = 1e18;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<array<int, 2>> a(n);
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1] >> a[i][0];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        dp[0][i] = a[i][1];
    }
    for (int i = 1; i < n; ++i) {
        ll cur = INF;
        for (int j = 0; j < n; ++j) {
            dp[i][j] = min(cur + a[j][1] + a[j][0], INF);
            cur = min(cur, dp[i - 1][j] - a[j][0]);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        ll cur = INF;
        for (int j = 0; j < n; ++j) {
            cur = min(cur, dp[i][j]);
        }
        if (cur <= l) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << "0\n";
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