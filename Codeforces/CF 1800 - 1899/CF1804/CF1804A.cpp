#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    x = abs(x);
    y = abs(y);
    cout << min(x, y) * 2 + abs(x - y) * 2 - (x != y) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}