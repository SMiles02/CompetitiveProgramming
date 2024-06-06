#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, k, a, b;
    cin >> m >> k >> a >> b;
    cout << ((m - min(m % k, a)) % k) + max((m / k) - b - (a - min(m % k, a)) / k, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}