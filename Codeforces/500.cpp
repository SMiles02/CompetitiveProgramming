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
    int n, x, y;
    cin >> n;
    string s[2];
    cin >> s[0];
    cin >> s[1];
    int dp[2][n];
    x = 0;
    y = n - 1;
    while (s[0][x] == '.' && s[1][x] == '.')
        ++x;
    while (s[0][y] == '.' && s[1][y] == '.')
        --y;
    if (s[0][x] == '*' && s[1][x] == '*')
        dp[0][x] = dp[1][x] = 1;
    else if (s[0][x] == '*') {
        dp[0][x] = 0;
        dp[1][x] = 1;
    }
    else {
        dp[0][x] = 1;
        dp[1][x] = 0;
    }
    for (int i = x + 1; i <= y; ++i) {
        if (s[0][i] == '*' && s[1][i] == '*')
            dp[0][i] = dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + 2;
        else if (s[0][i] == '*') {
            dp[0][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 2);
            dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + 2;
        }
        else if (s[1][i] == '*') {
            dp[1][i] = min(dp[1][i - 1] + 1, dp[0][i - 1] + 2);
            dp[0][i] = min(dp[1][i - 1], dp[0][i - 1]) + 2;
        }
        else {
            dp[0][i] = dp[0][i - 1] + 1;
            dp[1][i] = dp[1][i - 1] + 1;
        }
    }
    cout << min(dp[0][y], dp[1][y]) << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}