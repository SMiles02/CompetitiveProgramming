#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, k, ans = 100;
    cin >> n;
    vector<int> f(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        ++f[k];
    }
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, n - f[i]);
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