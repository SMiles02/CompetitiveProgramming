#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n], ans = 0;
    vector<int> dp(64);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 64; ++j)
            dp[a[i] & j] = add(dp[a[i] & j], dp[j]);
        dp[a[i]] = add(dp[a[i]], 1);
    }
    for (int i = 0; i < 64; ++i)
        if (__builtin_popcount(i) == k)
            ans = add(ans, dp[i]);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}