#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, n, m;
    cin >> a >> b;
    cin >> n >> m;
    cout << min(a * m, b * m + b) * (n / (m + 1)) + min(a, b) * (n % (m + 1)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}