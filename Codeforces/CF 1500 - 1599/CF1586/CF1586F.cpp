#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int k, ans, g[N][N];

void solve(int l, int r, int d) {
    if (l >= r) {
        return;
    }
    ans = max(ans, d);
    for (int i = l; i <= r; ++i) {
        for (int j = l + 1; j <= r; ++j) {
            g[i][j] = d;
        }
    }
    if (r - l + 1 < k) {
        return;
    }
    int extra = 0;
    for (int i = 0; i < k; ++i) {
        solve(l + i * ((r - l + 1) / k) + extra, l + (i + 1) * ((r - l + 1) / k) + extra - 1 + (i < ((r - l + 1) % k)), d + 1);
        extra += i < ((r - l + 1) % k);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n >> k;
    solve(1, n, 1);
    cout << ans << "\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            cout << g[i][j] << " ";
        }
    }
    return 0;
}