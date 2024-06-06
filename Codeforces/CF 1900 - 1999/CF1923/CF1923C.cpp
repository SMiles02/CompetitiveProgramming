#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    vector<ll> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = b[i - 1] + (a[i] == 1);
        p[i] = p[i - 1] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r || 2LL * (r - l + 1) - p[r] + p[l - 1] + b[r] - b[l - 1] > r - l + 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
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