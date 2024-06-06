#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    long long ans = n;
    for (int i = 2; i <= m; ++i) {
        ans += (n + i) / (1LL * i * i);
    }
    cout << ans << "\n";  
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