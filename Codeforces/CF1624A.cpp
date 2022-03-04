#include <bits/stdc++.h>
using namespace std;

void solve() {
    int mn = 1e9, mx = 1, n, k;
    cin >> n;
    while (n--) {
        cin >> k;
        mn = min(mn, k);
        mx = max(mx, k);
    }
    cout << mx - mn << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}