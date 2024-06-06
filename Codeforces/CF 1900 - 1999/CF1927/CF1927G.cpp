#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> dp(n, vector<int>(n, 1e5)); 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[max(i - a[i] + 1, 0)][i] = 1;
        dp[i][min(i + a[i] - 1, n - 1)] = 1;
    }
    for (int j = 0; j < n; ++j) {
        for (int i = j; i >= 0; --i) {
            for (int x = i; x < j; ++x) {
                for (int y = i; y < )
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
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