#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    a[n] = a[0];
    b[n] = b[0];
    if (k == 0) {
        if (a == b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else {
        vector<array<int, 2>> v(n), w(n);
        for (int i = 0; i < n; ++i)
            v[i] = {a[i], a[i + 1]};
        for (int i = 0; i < n; ++i)
            w[i] = {b[i], b[i + 1]};
        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        if (v != w || (k == 1 && a[0] == b[0]) || (n == 2 && a[0] != b[k & 1]))
            cout << "NO\n";
        else
            cout << "YES\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}