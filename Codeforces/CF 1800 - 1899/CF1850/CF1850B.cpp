#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    array<int, 2> ans = {-1, -1};
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x <= 10) {
            ans = max(ans, {y, i});
        }
    }
    cout << ans[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}