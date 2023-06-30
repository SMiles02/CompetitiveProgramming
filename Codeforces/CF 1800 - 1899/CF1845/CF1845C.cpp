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
    int n, m;
    string s, l, r;
    cin >> s;
    n = s.size();
    cin >> m;
    cin >> l;
    cin >> r;
    ll ans = 1;
    for (int i = 0; i < m; ++i) {
        ans *= (r[i] - l[i]) + 1;
    }

    vector<vector<ll>> dp(n + 4, vector<ll>(m + 1));
    vector<vector<int>> next_digit(n + 4, vector<int>(10, n + 3));
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < 10; ++j)
            next_digit[i - 1][j] = next_digit[i][j];
        next_digit[i - 1][s[i - 1] - '0'] = i;
        // i + 2 because 1-indexed
    }

    for (int x = (l[0] - '0'); x <= (r[0] - '0'); ++x)
        dp[next_digit[0][x]][1] = 1;

    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j < 10; ++j)
    //         cout << next_digit[i][j] << " ";
    //     cout << "\n";
    // }

    // dp[i][j] corresponds to count of passwords
    // such that there exists a password of length j,
    // first made up by the first i chars of s

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < m; ++j)
            for (int k = (l[j] - '0'); k <= (r[j] - '0'); ++k)
                dp[next_digit[i][k]][j + 1] += dp[i][j];
    
    for (int i = 1; i <= n; ++i)
        ans -= dp[i][m];

    if (ans == 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}