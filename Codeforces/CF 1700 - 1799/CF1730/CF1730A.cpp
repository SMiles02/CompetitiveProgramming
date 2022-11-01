#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c, ans = 0, x;
    cin >> n >> c;
    vector<int> f(101);
    while (n--) {
        cin >> x;
        ++f[x];
    }
    for (int i = 1; i < 101; ++i)
        ans += min(c, f[i]);
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