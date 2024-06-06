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

const int N = 1e5 + 4;
int dp[N][3], m, k;
vector<int> e[N];

void dfs(int c, int p) {
    dp[c][0] = 0;
    dp[c][1] = 1;
    dp[c][2] = 0;
    for (int i : e[c]) {
        if (i == p) {
            continue;
        }
        dfs(i, c);
        dp[c][0] += dp[i][0];
        dp[c][1] += dp[i][1];
        dp[c][2] += dp[i][1] == 0;
    }
    if (dp[c][1] >= m) {
        dp[c][1] = 0;
        ++dp[c][0];
    }
    // cout << c << ": " << dp[c][0] << " " << dp[c][1] << "\n";
}

void solve() {
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int l = 1, r = n / (k + 1);
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        dfs(1, 0);
        if (dp[1][0] > k || (dp[1][0] == k && dp[1][2] != e[1].size())) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    cout << l << "\n";
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