#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    vector<int> v(n), w(k);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        ans += max(0, v[i] - w[i % k]);
        w[i % k] = max(w[i % k], v[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}