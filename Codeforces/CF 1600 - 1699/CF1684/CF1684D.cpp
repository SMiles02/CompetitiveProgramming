#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, traps = 0;
    long long ans = 0;
    cin >> n >> k;
    int a[n];
    array<int, 2> b[n];
    vector<bool> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = {a[i] + i, i};
    }
    sort(b, b + n);
    for (int i = 1; i <= k; ++i)
        c[b[n - i][1]] = true;
    for (int i = 0; i < n; ++i) {
        if (c[i])
            ++traps;
        else
            ans += a[i] + traps;
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