#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, x;
    cin >> n;
    vector<int> a(n), b(n);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    if (a == b) {
        cout << "YES\n";
        return;
    }
    if (a[0] <= 0 || s != 0 || n == 1) {
        cout << "NO\n";
        return;
    }
    b[0] = a[0];
    b[1] = -a[0];
    for (int i = 1; i < n; ++i) {
        if (i == n - 1 || a[i] <= b[i]) {
            if (a == b)
                cout << "YES\n";
            else
                cout << "NO\n";
            return;
        }
        x = a[i] - b[i];
        if (x <= 0) {
            while (1)
                ++x;
        }
        b[i] += x;
        b[i + 1] -= x;
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