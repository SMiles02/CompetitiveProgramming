#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    if (a[0] != 1) {
        cout << "NO\n";
        return;
    }
    long long r = 1;
    for (int i = 1; i < n; ++i) {
        if (r < a[i]) {
            cout << "NO\n";
            return;
        }
        r += a[i];
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}