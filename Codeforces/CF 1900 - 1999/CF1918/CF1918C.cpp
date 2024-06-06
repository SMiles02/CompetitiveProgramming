#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    ll a, b, r, c, ans, ap, bp, cur1 = 0, cur2 = 0;
    cin >> a >> b >> r;
    if (a > b) {
        swap(a, b);
    }
    if (a == b) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < 60; ++i) {
        if ((a & (1LL << i)) != (b & (1LL << i))) {
            c = i;
        }
    }
    ans = b - a;
    // keep a < b
    ap = a;
    bp = b;
    for (int i = c - 1; i >= 0; --i) {
        if (!(a & (1LL << i)) && (b & (1LL << i)) && cur1 + (1LL << i) <= r) {
            cur1 ^= 1LL << i;
            ap ^= 1LL << i;
            bp ^= 1LL << i;
        }
    }
    ans = min(ans, bp - ap);
    // change to a > b
    ap = a;
    bp = b;
    if (cur2 + (1LL << c) <= r) {
        cur2 ^= 1LL << c;
        ap ^= 1LL << c;
        bp ^= 1LL << c;
        // cout << cur2 << " " << ap << " " << bp << "\n";
        for (int i = c - 1; i >= 0; --i) {
            if ((a & (1LL << i)) && !(b & (1LL << i)) && cur2 + (1LL << i) <= r) {
                cur2 ^= 1LL << i;
                ap ^= 1LL << i;
                bp ^= 1LL << i;
            }
        }
        ans = min(ans, ap - bp);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}