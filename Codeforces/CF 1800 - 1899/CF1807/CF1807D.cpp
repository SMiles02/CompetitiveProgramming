#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q, l, r, k;
    cin >> n >> q;
    vector<long long> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i] += p[i - 1];
    }
    while (q--) {
        cin >> l >> r >> k;
        if ((p[n] - p[r] + p[l - 1] + 1LL * k * (r - l + 1)) & 1)
            cout << "YES\n";
        else
            cout << "NO\n";
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