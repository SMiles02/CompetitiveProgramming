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

ll rev(ll n) {
    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    ll x = 0;
    for (int i : v)
        x = x * 10 + i;
    return x;
}

ll solve(ll n) {
    // cout << n << ": ";
    for (int i = 0; i < 30; ++i)
        n = rev(n);
    // cout << min(n, rev(n)) << "\n";
    return min(n, rev(n));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k, a, b;
    cin >> n >> k;
    a = k;
    b = rev(k);
    set<ll> s;
    while (a <= n) {
        if (solve(a) == k)
            s.insert(a);
        a *= 10;
    }
    while (b <= n) {
        if (solve(b) == k)
            s.insert(b);
        b *= 10;
    }
    cout << s.size();
    return 0;
}