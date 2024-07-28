#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n) {
            a[i] |= b[i];
        }
        if (0 <= i - 1) {
            a[i] |= b[i - 1];
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (b[i] != (a[i] & a[i + 1])) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
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