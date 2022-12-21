#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, -1)), b(n + 1, vector<int>(m + 1, 1e9)), dp(n + 1, vector<int>(m + 1, 1e9));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    dp[0][0] = a[0][0];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if ((i + j) & 1) {
                if (a[i + 1][j] > a[i][j + 1])
                    dp[i + 1][j] = min(dp[i + 1][j], max(dp[i][j], a[i + 1][j]));
                else
                    dp[i][j + 1] = min(dp[i][j + 1], max(dp[i][j], a[i][j + 1]));
            }
            else {
                dp[i + 1][j] = min(dp[i + 1][j], max(dp[i][j], a[i + 1][j]));
                dp[i][j + 1] = min(dp[i][j + 1], max(dp[i][j], a[i][j + 1]));
            }
        }
    cout << dp[n - 1][m - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}