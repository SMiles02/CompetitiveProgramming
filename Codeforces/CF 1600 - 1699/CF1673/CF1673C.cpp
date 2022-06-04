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

bool is_palindrome(int x) {
    vector<int> v;
    while (x) {
        v.push_back(x % 10);
        x /= 10;
    }
    for (int i = 0; i < v.size(); ++i)
        if (v[i] != v[v.size() - i - 1])
            return false;
    return true;
}

const int N = 4e4 + 1, MOD = 1e9 + 7;
vector<vector<int>> dp(2, vector<int> (N + 1));

void solve() {
    int n;
    cin >> n;
    cout << dp[0][n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    dp[0][0] = 1; 
    for (int i = 1; i <= N; ++i) {
        if (!is_palindrome(i))
            continue;
        for (int j = 0; j < i; ++j)
            dp[1][j] = dp[0][j];
        for (int j = i; j <= N; ++j)
            dp[1][j] = (dp[0][j] + dp[1][j - i]) % MOD;
        swap(dp[0], dp[1]);
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}