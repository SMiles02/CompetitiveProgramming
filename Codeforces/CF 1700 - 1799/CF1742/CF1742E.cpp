#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q, x, l, r, m;
    cin >> n >> q;
    long long p[n + 1];
    int mx[n + 1];
    p[0] = 0;
    mx[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        p[i] = p[i - 1] + x;
        mx[i] = max(mx[i - 1], x);
    }
    while (q--) {
        cin >> x;
        l = 0;
        r = n;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (mx[m] > x)
                r = m - 1;
            else
                l = m;
        }
        cout << p[l] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}