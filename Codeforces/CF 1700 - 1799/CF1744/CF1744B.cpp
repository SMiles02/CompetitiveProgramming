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
    int n, q, k, x, a = 0, b = 0;
    ll s = 0;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        s += k;
        if (k & 1)
            ++a;
        else
            ++b;
    }
    // cout << a << " " << b << "\n";
    while (q--) {
        cin >> k >> x;
        if (k == 0) {
            s += 1LL * x * b;
            if (x & 1) {
                b = 0;
                a = n;
            }
        }
        else {
            s += 1LL * x * a;
            if (x & 1) {
                a = 0;
                b = n;
            }
        }
        cout << s << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}