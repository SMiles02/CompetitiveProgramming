#include <bits/stdc++.h>
using namespace std;

const int SN = 1420;
bitset<SN> bad[SN];

void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i * i <= n; ++i) {
        for (int j = 1; j * j <= m; ++j) {
            if (!bad[i][j]) {
                ans += min(n / i, m / j) / (i + j);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < SN; ++i) {
        for (int x = i; x < SN; x += i) {
            for (int y = i; y < SN; y += i) {
                bad[x][y] = 1;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}