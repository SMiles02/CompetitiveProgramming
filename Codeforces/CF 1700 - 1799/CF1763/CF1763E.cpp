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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, tot;
    cin >> n;
    vector<array<int, 2>> dp(n + 1, {INF, 0});
    dp[0] = {0, 0};
    for (int i = 1; i < 700; ++i) {
        m = (i * (i - 1)) / 2;
        for (int j = m; j <= n; ++j)
            dp[j] = min(dp[j], {dp[j - m][0] + i, i});
    }
    tot = dp[n][0];
    cout << tot << " ";
    long long ans = 0;
    while (n > 0) {
        ans += 1LL * (tot - dp[n][1]) * dp[n][1];
        tot -= dp[n][1];
        n -= (dp[n][1] * (dp[n][1] - 1)) / 2;
    }
    cout << ans;
    return 0;
}