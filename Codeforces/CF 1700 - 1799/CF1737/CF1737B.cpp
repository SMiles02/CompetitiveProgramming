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

bool in_range(ll l, ll x, ll r) {
    return l <= x && x <= r;
}

ll check_for(ll l, ll x, ll r) {
    ll ret = 0;
    ret += in_range(l, x * x, r);
    ret += in_range(l, x * (x + 1), r);
    ret += in_range(l, x * (x + 2), r);
    return ret;
}

ll stupid(ll x) {
    ll l = 1, r = 1e9, m;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        if (m * m > x)
            r = m - 1;
        else
            l = m;
    }
    return l;
}

void solve() {
    ll l, r, x, y, ans = 0;
    cin >> l >> r;
    x = stupid(l);
    y = stupid(r);
    // cout << x << " " << y << "\n";
    ans += check_for(l, x, r);
    ans += max(0LL, y - x - 1) * 3;
    if (r >= (x + 1) * (x + 1))
        ans += check_for(l, y, r);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}