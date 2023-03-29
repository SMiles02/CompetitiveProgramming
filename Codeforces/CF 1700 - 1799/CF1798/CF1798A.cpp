#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > b[i])
            swap(a[i], b[i]);
        if (a[i] > a[n - 1] || b[i] > b[n - 1]) {
            cout << "NO\n";
            return;
        }
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