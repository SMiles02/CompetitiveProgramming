// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, l, k;
    cin >> n >> l >> k;
    int a[n], d[n + 1];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    d[n] = l;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= k; ++j) {
            if (j > 1)
                dp[i][j] = dp[i][j - 1];
            for (int l = 0; l < i && l <= j; ++l)
                dp[i][j] = min(dp[i][j], dp[i - l - 1][j - l] + a[i - l - 1] * (d[i] - d[i - l - 1]));
        }
    cout << dp[n][k] << "\n";
    return 0;
}