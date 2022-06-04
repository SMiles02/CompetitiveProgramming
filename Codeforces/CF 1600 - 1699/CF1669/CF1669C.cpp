#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    bool o, e;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int j = 0; j < 2; ++j) {
        o = 0; e = 0;
        for (int i = j; i < n; i += 2) {
            if (a[i] & 1)
                o = 1;
            else
                e = 1;
        }
        if (o & e) {
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