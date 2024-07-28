#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        if (i % 2 == 0) {
            ans = max(ans, k);
        }
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