#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    cout << abs(min({a, b, n - a + 1, n - b + 1}) - min({c, d, n - c + 1, n - d + 1})) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}