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
    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 1, 1e9);
    dp[0] = 0;
    while (n--) {
        int a, b, x, y, c = 0, d = 0;
        cin >> a >> b;
        vector<int> newdp(k + 1, 1e9);
        x = a;
        y = b;
        while (min(x, y) > 0 && d < k) {
            ++d;
            c += min(x, y);
            for (int i = d; i <= k; ++i) {
                newdp[i] = min(newdp[i], dp[i - d] + c);
            }
            if (x > y) {
                --x;
            }
            else {
                --y;
            }
        }
        if (min(x, y) == 0) {
            ++d;
            for (int i = d; i <= k; ++i) {
                newdp[i] = min(newdp[i], dp[i - d] + c);
            }
        }
        for (int i = 0; i <= k; ++i) {
            dp[i] = min(dp[i], newdp[i]);
        }
    }
    if (dp[k] == 1e9) {
        dp[k] = -1;
    }
    cout << dp[k] << "\n";
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