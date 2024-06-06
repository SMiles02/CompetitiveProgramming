#include <bits/stdc++.h>
using namespace std;

const int N = 5001;
double f[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n + 1);
    vector<double> dp(n + 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
    }
    dp[n] = 1;
    for (int i = n - 1; i >= 1; --i) {
        vector<double> v;
        for (int j : e[i]) {
            v.push_back(dp[j]);
        }
        sort(v.rbegin(), v.rend());
        for (int j = 0; j < v.size(); ++j) {
            dp[i] += v[j] * f[e[i].size()][j + 1];
        }
    }
    cout << fixed << setprecision(15) << dp[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[1][1] = 1;
    f[2][1] = 0.5;
    for (int i = 3; i < N; ++i) {
        f[i][1] = double(1) / i;
        for (int j = 2; j <= i; ++j) {
            f[i][j] = (f[i - 2][j - 2] * (j - 2)) / i + (f[i - 2][j - 1] * (i - j)) / i;
        }
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}