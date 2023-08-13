#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll l = 1, r = 1e11, m;
    while (l < r) {
        m = l + (r - l) / 2;
        ll del_before = 0;
        int rp = n - 1;
        for (int i = 0; i < k; ++i) {
            while (rp >= 0 && a[rp] > m - del_before) {
                --rp;
            }
            del_before += rp + 1;
        }
        if (del_before < m) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}