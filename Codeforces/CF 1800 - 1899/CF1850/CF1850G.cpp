#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    vector<map<int, int>> m(4);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++m[0][x];
        ++m[1][y];
        ++m[2][x + y];
        ++m[3][x - y];
    }
    for (auto& mp : m) {
        for (auto& [x, cnt] : mp) {
            ans += 1LL * cnt * (cnt - 1);
        }
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