#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x, y;
    cin >> n;
    vector<int> a(n + 2), p(n + 2), q(n + 2);
    a[0] = -2e9;
    a[n + 1] = 2e9;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    p[1] = a[1];
    p[2] = a[1] + 1;
    for (int i = 3; i <= n; ++i) {
        if (a[i] - a[i - 1] < a[i - 1] - a[i - 2]) {
            p[i] = p[i - 1] + 1;
        }
        else {
            p[i] = p[i - 1] + a[i] - a[i - 1];
        }
    }
    q[n] = a[n];
    q[n - 1] = a[n] + 1;
    for (int i = n - 2; i >= 1; --i) {
        if (a[i + 1] - a[i] < a[i + 2] - a[i + 1]) {
            q[i] = q[i + 1] + 1;
        }
        else {
            q[i] = q[i + 1] + a[i + 1] - a[i];
        }
    }
    cin >> m;
    while (m--) {
        cin >> x >> y;
        if (x < y) {
            cout << p[y] - p[x] << "\n";
        }
        else {
            cout << q[y] - q[x] << "\n";
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