#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
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

const int N = 32000;
bitset<N> sieve;

void solve() {
    int x, d, s, k;
    cin >> x >> d;
    vector<int> v;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            v.push_back(i);
            if (i * i != x)
                v.push_back(x / i);
        }
    }
    sort(v.begin(), v.end());
    s = v.size();
    ll dp[s][s];
    map<int, int> m;
    for (int i = 0; i < s; ++i)
        m[v[i]] = i;
    for (int i = 1; i < s; ++i)
        if (v[i] % 1LL * d * d == 0)
            for (int j = i; j >= 0; --j) {
                k = 
            }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i < N; ++i)
        sieve[i] = 1;
    for (int i = 2; i < N; ++i)
        if (sieve[i])
            for (int j = i * 2; j < N; j += i)
                sieve[j] = 0;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}