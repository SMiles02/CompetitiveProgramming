#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 0, y = 0, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (k & 1)
            y += k;
        else
            x += k;
    }
    if (x > y)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}