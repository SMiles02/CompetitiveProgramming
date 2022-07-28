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
    int n, c, q;
    ll x, l, r, m;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    array<ll, 4> a[c + 1];
    x = n;
    a[0] = {1, n, 1, n};
    for (int i = 1; i <= c; ++i) {
        cin >> l >> r;
        a[i] = {x + 1, x + r - l + 1, l, r};
        x += r - l + 1;
    }
    while (q--) {
        cin >> x;
        while (x > n) {
            l = 1;
            r = c;
            while (l < r) {
                m = l + (r - l) / 2;
                if (a[m][1] < x)
                    l = m + 1;
                else
                    r = m;
            }
            x = x - a[l][0] + a[l][2];
        }
        cout << s[x - 1] << "\n";
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