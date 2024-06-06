#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll and_seq(ll l, ll r) {
    ll ans = 0;
    for (int i = 60; i >= 0; --i) {
        if (r - l + 1 <= (1LL << i) && (l & (1LL << i)) && (r & (1LL << i))) {
            ans += 1LL << i;
        }
    }
    return ans;
}

void solve() {
    ll n, x, l, r, m;
    cin >> n >> x;
    if (n == x) {
        cout << n << "\n";
        return;
    }
    l = n;
    r = n + (1LL << 60);
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        if (and_seq(n, m) > x) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    if (and_seq(n, l + 1) == x) {
        cout << l + 1 << "\n";
    }
    else {
        cout << "-1\n";
    }
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