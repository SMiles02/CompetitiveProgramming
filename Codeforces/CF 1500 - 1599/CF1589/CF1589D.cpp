#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ai, aj, ak;
bool local = false;

ll f(int x) {
    return (1LL * x * (x - 1)) / 2;
}

ll make_query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    ll ans;
    if (local) {
        ans = 0;
        ll a = 0, b = 0;
        int tl = max(l, ai), tr = min(r, aj - 1);
        if (tl <= tr) {
            a = f(tr - tl + 1);
        }
        tl = max(l, aj), tr = min(r, ak);
        if (tl <= tr) {
            b = f(tr - tl + 1);
        }
        ans = a + b;
        cout << "Query Answer: " << ans << endl;
    }
    else {
        cin >> ans;
    }
    return ans;
}

void solve() {
    int n, l, r, m, i, j, k;
    cin >> n;
    if (local) {
        cin >> ai >> aj >> ak;
    }
    ll tot = make_query(1, n), tmp;
    l = 1;
    r = n - 2;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        if (make_query(m, n) == tot) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    i = l;
    // cout << "i is " << i << endl;
    tmp = make_query(i + 1, n);
    j = i + tot - tmp + 1;
    // cout << "j is " << j << endl;
    l = j + 1;
    r = n;
    while (l < r) {
        m = l + (r - l) / 2;
        // cout << "Trying " << m << " for k" << endl;
        // cout << f(j - i) + f(m - j + 1) << " vs " << tot << " expected" << endl;
        if (f(j - i) + f(m - j + 1) < tot) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    k = l;
    cout << "! " << i << " " << j << " " << k << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}