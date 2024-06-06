#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, ans = 0;
    cin >> n;
    vector<int> f(101);
    while (n--) {
        cin >> k;
        ans += ++f[k] % 3 == 0;
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