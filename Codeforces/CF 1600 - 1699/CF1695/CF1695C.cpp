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
    vector<vector<int>> a(n + 1, vector<int>(m + 1)), dpMin(n + 1, vector<int>(m + 1, 1e9)), dpMax(n + 1, vector<int>(m + 1, -1e9));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            dpMin[i][j] = min(dpMin[i - 1][j], dpMin[i][j - 1]);
            dpMax[i][j] = max(dpMax[i - 1][j], dpMax[i][j - 1]);
            if (i == 1 && j == 1)
                dpMin[i][j] = dpMax[i][j] = 0;
            dpMin[i][j] += (a[i][j] == 1);
            dpMax[i][j] += (a[i][j] == 1);
            // cerr << dpMin[i][j] << " " << dpMax[i][j] << "\n";
        }
    // cout << n + m - 1 << " " << dpMin[n][m] << " " << dpMax[n][m] << "\n";
    // cout << (n + m - 1 % 2 == 0) << " " << (dpMin[n][m] <= (n + m - 1) / 2) << " " << ((n + m - 1) / 2 <= dpMax[n][m]) << "\n";
    if ((n + m - 1) % 2 == 0 && dpMin[n][m] <= (n + m - 1) / 2 && (n + m - 1) / 2 <= dpMax[n][m])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}