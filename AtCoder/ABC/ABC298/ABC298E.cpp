#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353, N = 102;
int f[N], inv[N];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a, binpow(b, MOD - 2)); }

int sub(int a, int b) { return add(a, MOD - b); }

int C(int n, int k) { return dv(f[n], mul(f[k], f[n - k])); }

void calc_factorials() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
    for (int i = 1; i < N; ++i) inv[i] = binpow(i, MOD - 2);
}

int dp[202][202][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    int n, a, b, p, q, ans = 0;
    cin >> n >> a >> b >> p >> q;
    dp[a][b][0] = 1;
    for (int k = a + b; k < n * 2; ++k)
        for (int i = a; i <= k; ++i) {
            int j = k - i;
            if (!(b <= j && i < n && j < n))
                continue;
            // cout << i << " " << j << ": " << dp[i][j][0] << " " << dp[i][j][1] << "\n";
            for (int r = 1; r <= p; ++r) {
                if (i + r >= n)
                    ans = add(ans, mul(dp[i][j][0], inv[p]));
                else
                    dp[i + r][j][1] = add(dp[i + r][j][1], mul(dp[i][j][0], inv[p]));
            }
            for (int r = 1; r <= q; ++r)
                if (j + r < n)
                    dp[i][j + r][0] = add(dp[i][j + r][0], mul(dp[i][j][1], inv[q]));
        }
    cout << ans;
    return 0;
}