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
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<array<bool, 2>> dp(4);
    vector<array<int, 2>> p = {{0, 0}, {0, m - 1}, {n - 1, 0}, {n - 1, m - 1}};
    for (int i = 0; i < 4; ++i) {
        auto [x, y] = p[i];
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (s[r][y] == s[x][c]) {
                    if (s[r][y] == 'B') {
                        dp[i][0] = true;
                    }
                    else {
                        dp[i][1] = true;
                    }
                }
            }
        }
    }
    bool ans = false;
    for (int i = 0; i < 2; ++i) {
        ans |= (dp[0][i] && dp[3][i]) || (dp[1][i] && dp[2][i]);
    }
    if (ans) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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