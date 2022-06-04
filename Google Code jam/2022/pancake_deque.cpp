#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0, cur = 0;
    cin >> n;
    int a[n], x = 0, y = n - 1;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    while (x <= y) {
        if (a[x] < a[y]) {
            ans += (a[x] >= cur);
            cur = max(cur, a[x]);
            ++x;
        }
        else {
            ans += (a[y] >= cur);
            cur = max(cur, a[y]);
            --y;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}