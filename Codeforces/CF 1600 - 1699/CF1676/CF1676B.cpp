#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, mn = 1e9, x, s = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s += x;
        mn = min(mn, x);
    }
    cout << s - n * mn << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}