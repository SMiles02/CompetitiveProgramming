#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 7, L = 42;
int dp[L][N], w[N * 3];
ll p[N * 3], sz[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, x, y, l, r, m;
    cin >> n >> q >> x;
    ll s = 0, k;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        s += w[i];
    }
    for (int i = 1; i <= n * 3; ++i) {
        if (i > n)
            w[i] = w[i - n];
        p[i] = p[i - 1] + w[i];
    }
    y = x % (s * 2);
    for (int i = 1; i <= n; ++i) {
        sz[i] = 2LL * n * (x / (s * 2));
        l = 0;
        r = n * 2;
        while (l < r) {
            m = l + (r - l) / 2;
            if (p[i + m] - p[i - 1] >= y)
                r = m;
            else
                l = m + 1;
        }
        sz[i] += l + 1;
        l += i + 1;
        while (l > n)
            l -= n;
        dp[0][i] = l;
    }
    for (int i = 1; i < L; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
    while (q--) {
        cin >> k;
        --k;
        x = 1;
        for (int i = L - 1; i >= 0; --i)
            if ((1LL << i) & k)
                x = dp[i][x];
        cout << sz[x] << "\n";
    }
    return 0;
}