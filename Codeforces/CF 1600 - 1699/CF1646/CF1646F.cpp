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

const int N = 1e3;
vector<int> dp(N + 1, 1e9);

void knapsack(int weight) {
    for (int i = N; i >= weight; --i)
        dp[i] = min(dp[i], dp[i - weight] + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, c = 1, mx = 0;
    cin >> n;
    dp[0] = 0;
    for (int i = 2; (1 << i) < N; ++i)
        knapsack(1 << i);
    for (int i = 1; 1LL * c * i < N; ++i) {
        c *= i;
        knapsack(c);
    }
    for (int i = 1; i <= N; ++i) {
        cout << i << ": " << dp[i] << "\n";
        mx = max(mx, dp[i]);
    }
    cout << mx;
    return 0;
}