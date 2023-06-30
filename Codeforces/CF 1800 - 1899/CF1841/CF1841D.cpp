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
    int n, ans = 0;
    cin >> n;
    array<int, 2> a[n + 1];
    vector<int> dp(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i][1] >> a[i][0];
    a[n] = {-1, -1};
    sort(a, a + n + 1);
    for (int j = 1; j <= n; ++j) {
        // cout << a[j][1] << " " << a[j][0] << "\n";
        int l = -100;
        for (int i = j - 1; i >= 0; --i) {
            if (a[j][1] <= a[i][0])
                l = max(l, min(a[i][1], a[j][1]));
            else if (a[i][0] < l)
                dp[j] = max(dp[j], dp[i] + 2);
        }
        ans = max(ans, dp[j]);
        // cout << dp[j] << "\n";
    }
    cout << n - ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}